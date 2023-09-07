#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#define INF 100000000

using namespace std;

int moveFeet[5][5] = {
    {0, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};
int dp[5][5][100002];
int ans = INF;
pair<int, int> feet;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    if (n != 0) {
        dp[0][n][cnt] = 2;
        dp[n][0][cnt] = 2;
        cnt++;
        cin >> n;
    }
    while (n != 0) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (dp[i][j][cnt - 1] > 0) {
                    if (i == n || j == n) {
                        if(dp[i][j][cnt] == 0)
                            dp[i][j][cnt] = dp[i][j][cnt - 1] + 1;
                        else
                            dp[i][j][cnt] = min(dp[i][j][cnt], dp[i][j][cnt - 1] + 1);
                        continue;
                    }
                    if (dp[i][n][cnt] == 0)
                        dp[i][n][cnt] = dp[i][j][cnt - 1] + moveFeet[j][n];
                    else
                        dp[i][n][cnt] = min(dp[i][n][cnt], dp[i][j][cnt - 1] + moveFeet[j][n]);
                    if (dp[n][j][cnt] == 0)
                        dp[n][j][cnt] = dp[i][j][cnt - 1] + moveFeet[i][n];
                    else
                        dp[n][j][cnt] = min(dp[n][j][cnt], dp[i][j][cnt - 1] + moveFeet[i][n]);
                }
            }
        }
        cnt++;
        cin >> n;
    }
    cnt--;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (dp[i][j][cnt] > 0)
                ans = min(ans, dp[i][j][cnt]);
        }
    }
    cout << ans;
    return 0;
}