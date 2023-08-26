#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define INF -1000000007
using namespace std;

int N, M;
pair<int, int> app[101];
int dp[101][10001];
int sum = 0;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> app[i].first;
	}
	for (int i = 1; i <= N; i++) {
		cin >> app[i].second;
		sum += app[i].second;
	}
}

void Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			int curByte = app[i].first;
			int curCost = app[i].second;
			if (curCost <= j) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - curCost] + curByte);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i <= sum; i++) {
		if (dp[N][i] >= M) {
			cout << i << "\n";
			return;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}