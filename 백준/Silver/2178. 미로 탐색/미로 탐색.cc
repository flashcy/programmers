#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int maze[102][102];
bool visited[102][102];
int N, M;

queue<pair<int, pair<int, int>>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int f_ans = 1000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char k;
			cin >> k;
			maze[i][j] = k - '0';
		}
	}

	q.push({ 1,{ 1,1 } });
	visited[1][1] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		if (x == M && y == N) {
			f_ans = min(f_ans, cnt);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny > N || nx > M || ny <= 0 || nx <= 0)continue;
			if (maze[ny][nx] == 0 || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({ cnt + 1, {ny, nx} });
		}
	}
	cout << f_ans << '\n';
}