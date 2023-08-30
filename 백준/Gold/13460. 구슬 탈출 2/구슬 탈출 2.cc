#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#define INF 2000000007
using namespace std;

int N, M;
int map[10][10];
pair<int, int> redBall;
pair<int, int> blueBall;
queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '.') map[i][j] = 1;
			else if (c == 'O') map[i][j] = 2;
			else if (c == 'R') {
				redBall = { i,j };
				map[i][j] = 1;
			}
			else if (c == 'B') {
				blueBall = { i,j };
				map[i][j] = 1;
			}
		}
	}
}

void Solve() {
	int answer = INF;
	q.push({ 0, { redBall, blueBall } });
	while (!q.empty()) {
		int cnt = q.front().first;
		int ry = q.front().second.first.first;
		int rx = q.front().second.first.second;
		int by = q.front().second.second.first;
		int bx = q.front().second.second.second;
		q.pop();

		if (cnt == 10) break;

		for (int i = 0; i < 4; i++) {
			int result = INF;
			bool blueGoal = false;

			int nry = ry + dy[i];
			int nrx = rx + dx[i];
			bool meet = false;
			while (nry >= 0 && nry < N && nrx >= 0 && nrx < M && map[nry][nrx] != 0) {
				if (map[nry][nrx] == 2) {
					result = min(result, cnt + 1);
				}
				if (nry == by && nrx == bx) meet = true;
				nry += dy[i];
				nrx += dx[i];
			}
			nry -= dy[i];
			nrx -= dx[i];
			if (meet) {
				nry -= dy[i];
				nrx -= dx[i];
			}

			int nby = by + dy[i];
			int nbx = bx + dx[i];
			meet = false;
			while (nby >= 0 && nby < N && nbx >= 0 && nbx < M && map[nby][nbx] != 0) {
				if (map[nby][nbx] == 2) {
					blueGoal = true;
				}
				if (ry == nby && rx == nbx) meet = true;
				nby += dy[i];
				nbx += dx[i];
			}
			nby -= dy[i];
			nbx -= dx[i];
			if (meet) {
				nby -= dy[i];
				nbx -= dx[i];
			}
			if (result != INF && !blueGoal)
				answer = min(answer, result);
			if (!blueGoal && !(nry == ry && nrx == rx && nby == by && nbx == bx))
				q.push({ cnt + 1, { {nry, nrx}, {nby, nbx} } });
		}
	}
	if (answer == INF)
		cout << "-1";
	else
		cout << answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}