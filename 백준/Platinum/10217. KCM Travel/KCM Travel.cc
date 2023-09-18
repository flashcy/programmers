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

typedef pair<int, int> pii;

int T;
int N, M, K;
vector<pair<int, pii>> air[101];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
int dist[101][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) {
			air[i].clear();
			for (int j = 0; j <= M; j++) {
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			air[u].push_back({ c,{v,d} });
		}
		for (int i = 1; i <= N; i++) {
			sort(air[i].begin(), air[i].end());
		}
		pq.push({ 0, {1, 0} });
		while (!pq.empty()) {
			int d = pq.top().first;
			int cur = pq.top().second.first;
			int cost = pq.top().second.second;
			pq.pop();

			if (dist[cur][cost] < d) continue;

			for (auto next : air[cur]) {
				int nc = next.first;
				int nv = next.second.first;
				int nd = next.second.second;

				if (nc + cost > M) continue;
				if (nd + d < dist[nv][nc + cost]) {
					for (int j = nc + cost + 1; j <= M; j++) {
						if (dist[nv][j] <= nd + d) break;
						dist[nv][j] = nd + d;
					}
					dist[nv][nc + cost] = nd + d;
					pq.push({ nd + d, {nv, nc + cost}});
				}
			}
		}
		int ans = INF;
		for (int i = 0; i <= M; i++) {
			ans = min(ans, dist[N][i]);
		}
		if (ans == INF)
			cout << "Poor KCM\n";
		else
			cout << ans << '\n';
	}

	return 0;
}

/*
1
3 10 3
1 2 9 1
2 3 2 10
1 2 3 10

*/