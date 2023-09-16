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

int grape[10001];
int dp[10001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> grape[i];
	}
	if (N == 1) cout << grape[0];
	else if (N == 2) cout << grape[0] + grape[1];
	else {
		int ans = 0;
		dp[0][0] = grape[0];
		for (int i = 1; i < N; i++) {
			dp[i][0] = dp[i - 1][2] + grape[i];
			dp[i][1] = dp[i - 1][0] + grape[i];
			dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
			ans = max(dp[i][0], max(dp[i][1], dp[i][2]));
		}
		cout << ans;
	}
	return 0;
}