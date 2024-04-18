#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, K;
ll factorial[16];
string input[16];
ll rem[16];
ll lenRem[51];
ll dp[1 << 15][101];

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    factorial[0] = 1;
    for (int i = 1; i < 16; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    cin >> K;
    for (int i = 0; i < N; i++) {
        int r = 0;
        for (int j = 0; j < input[i].size(); j++) {
            int n = input[i][j] - '0';
            r = (r * 10 + n) % K;
        }
        rem[i] = r;
    }

    lenRem[0] = 1 % K;
    for (int i = 1; i < 51; i++) {
        lenRem[i] = lenRem[i - 1] * 10 % K;
    }

    dp[0][0] = 1;
    for (int n = 0; n < (1 << 15); n++) {
        for (int i = 0; i < N; i++) {
            if ((n & (1 << i)) == 0) {
                int next = (n | (1 << i));
                for (int j = 0; j < K; j++) {
                    int nextRem = (j * lenRem[input[i].size()] % K + rem[i]) % K;
                    dp[next][nextRem] += dp[n][j];
                }
            }
        }
    }

    ll gcdAns = gcd(dp[(1 << N) - 1][0], factorial[N]);

    cout << dp[(1 << N) - 1][0] / gcdAns << '/' << factorial[N] / gcdAns;

    return 0;
}