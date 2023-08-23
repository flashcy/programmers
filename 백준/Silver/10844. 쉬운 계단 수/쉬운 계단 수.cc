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
long long dp[101][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j + 1] % MOD;
            else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % MOD;
            else dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD) % MOD;
        }
    }
    long long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = (sum % MOD + dp[N][i] % MOD) % MOD;
    }
    cout << sum;
    return 0;
}