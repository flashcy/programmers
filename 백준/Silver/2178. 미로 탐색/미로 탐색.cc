#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int maze[102][102];
int visited[102][102];
int dp[102][102];
int N, M;

queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int f_ans = 1000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char k;
			cin >> k;
			maze[i][j] = (int)k - 48;
		}
	}

	q.push({ 1,1 });
	visited[1][1] = 1;
	dp[1][1] = 1;
	int x = 0, y = 0;
	while (!(q.empty() || (x == M && y == N))) {
		x = q.front().first;
		y = q.front().second;

		for (int i = 0; i < 4; i++) {
			if (maze[y + dy[i]][x + dx[i]] == 1 && visited[y + dy[i]][x + dx[i]] == 0) {
				q.push({ x + dx[i],y + dy[i] });
				dp[y + dy[i]][x + dx[i]] = dp[y][x] + 1;
				visited[y + dy[i]][x + dx[i]] = 1;
			}
		}
		q.pop();
	}
	cout << dp[N][M] << '\n';
}