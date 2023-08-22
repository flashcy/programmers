#include <iostream>
#include <algorithm>

using namespace std;

int dp[1002][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    dp[0][0] = 1;
    dp[1][0] = 1, dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
        dp[i][i] = 1;
    }

    cout << dp[N][K];

    return 0;
}