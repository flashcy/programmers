#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int dp[10001];
int N, K;
int num[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    sort(num, num + N); 
    for (int i = 1; i <= K; i++) {
        dp[i] = INF;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= num[i]) {
                dp[j] = min(dp[j], dp[j - num[i]] + 1);
            }
        }
    }
    if (dp[K] == INF) cout << -1;
    else cout << dp[K];

    return 0;
}