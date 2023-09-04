#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M, K;
vector<pair<int, int>> cases;
int candy[30001];
vector<int> friends[100001];
bool visit[100001];
queue<int> q;

int dp[30001][3001];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> candy[i];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		q.push(i);
		visit[i] = true;
		int sum = 0;
		int cnt = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			sum += candy[cur];
			cnt++;

			for (auto next : friends[cur]) {
				if (visit[next]) continue;
				visit[next] = true;
				q.push(next);
			}
		}
		cases.push_back({ cnt, sum });
	}

	for (int i = 1; i <= cases.size(); i++) {
		for (int j = 1; j < K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= cases[i - 1].first) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cases[i - 1].first] + cases[i - 1].second);
			}
		}
	}

	cout << dp[cases.size()][K - 1];

	return 0;
}