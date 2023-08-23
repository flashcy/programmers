#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, M;
int arr[1002][1002];
int dp[1002][1002];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            if (arr[i][j]) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i-1][j-1], dp[i][j - 1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans << "\n";

    return 0;
}