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
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j == 0) {
                dp[j] = 1;
                continue;
            }
            if (j >= num[i])dp[j] += dp[j - num[i]];
        }
    }
    cout << dp[K];

    return 0;
}