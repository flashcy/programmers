#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <cstring>
#define MOD 1000000000

using namespace std;

int N;
int dp[101][10][4];

int chk(int n, int num, int bit) {
    int& ret = dp[n][num][bit];
    if (ret) return ret;

    if (n == N - 1) {
        if (bit == 3) return 1;
        else return 0;
    }

    if (num < 9) {
        ret += chk(n + 1, num + 1, bit | (num + 1 == 9 ? 2 : 0));
        ret %= MOD;
    }
    if (num > 0) {
        ret += chk(n + 1, num - 1, bit | (num - 1 == 0 ? 1 : 0));
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
        ans += chk(0, i, i == 9 ? 2 : 0);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}