#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#define INF 2000000007
using namespace std;

int N, M;
int indeg[32001];
vector<int> chi[32001];
int ans[32001];

void Input() {
	cin >> N >> M;
	int p, c;
	for (int i = 0; i < M; i++) {
		cin >> p >> c;
		indeg[c]++;
		chi[p].push_back(c); // p->c의 경로 생성.
	}
}

void Solve() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		if (q.empty()) return;
		int cur = q.front();
		ans[i] = cur;
		q.pop();

		for (auto next : chi[cur]) {
			if (--indeg[next] == 0) q.push(next);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}