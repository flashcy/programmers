#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#define INF 1000000001
#define MOD 1000000007
using namespace std;

pair<int, int> score[1001];
int dp[1002][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	int ans = 0;
	int s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		score[i].first = s;
	}
	for (int i = 1; i <= N; i++) {
		cin >> s;
		score[i].second = s;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 100; j++) {
			dp[i + 1][min(100, j + K)] = max(dp[i + 1][min(100, j + K)], dp[i][j]);
			if (j >= score[i].second) {
				dp[i + 1][min(100, j - score[i].second + K)] = max(dp[i + 1][min(100, j - score[i].second + K)], dp[i][j] + score[i].first);
			}
		}
	}
	for (int j = 0; j <= 100; j++) {
		ans = max(ans, dp[N + 1][j]);
	}
	cout << ans;
	return 0;
}