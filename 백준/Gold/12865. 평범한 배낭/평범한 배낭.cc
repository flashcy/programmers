#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define INF 2000000001
using namespace std;

int N, K;
long long knapsack[101][2];
long long dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> knapsack[i][0] >> knapsack[i][1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (knapsack[i][0] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - knapsack[i][0]] + knapsack[i][1]);
			}
		}
	}
	cout << dp[N][K] << "\n";

	return 0;
}