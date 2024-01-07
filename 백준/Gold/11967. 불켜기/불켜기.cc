#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<pair<int, int>> v[101][101];
queue<pair<int, int>> q;
bool visit[101][101];
//bool light[101][101];
bool check[101][101];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[y][x].push_back({ b,a });
	}
	// 갈 수 있는 곳을 모두 세어 놓은 후,
	/*q.push({ 1, 1 });
	light[1][1] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (pair<int, int> coord : v[y][x]) {
			if (light[coord.first][coord.second]) continue;
			q.push(coord);
			light[coord.first][coord.second] = true;
		}
	}*/
	q.push({ 1,1 });
	check[1][1] = true;
	int answer = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visit[y][x])continue;
		visit[y][x] = true;
		for (pair<int, int> coord : v[y][x]) {
			if (check[coord.first][coord.second]) continue;
			check[coord.first][coord.second] = true;
			answer++;
			bool poss = false;
			for (int i = 0; i < 4; i++) {
				int ny = coord.first + dy[i];
				int nx = coord.second + dx[i];
				if (ny <= 0 || nx <= 0 || ny > N || nx > N)continue;
				if (visit[ny][nx]) poss = true;
			}
			if (poss)
				q.push(coord);
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > N || nx > N || !check[ny][nx] || visit[ny][nx])continue;
			//visit[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	cout << answer << '\n';

	return 0;
}