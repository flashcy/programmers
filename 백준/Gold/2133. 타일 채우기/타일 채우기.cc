#include <iostream>
#include <algorithm>

using namespace std;

int dp[40];

int rec(int K) {
    if (K % 2 == 1) return 0;
    int ret = 0;
    for (int i = 0; i < K; i += 2) {
        ret += dp[i] * 2;
    }
    return ret + dp[K - 2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= N; i += 2) {
        dp[i] = rec(i);
    }

    cout << dp[N];

    return 0;
}