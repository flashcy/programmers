#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dice[6] = { 1, 2, 3, 5, 4, 6 }; 
			// 윗면, 북 동 남 서, 아랫면
int diceDirection = 1;
int diceY = 1;
int diceX = 1;

int score = 0;
int grid[21][21];

void RollDice() {
	if (diceY + dy[diceDirection] > N || diceX + dx[diceDirection] > M ||
		diceY + dy[diceDirection] <= 0 || diceX + dx[diceDirection] <= 0) {
		diceDirection = (diceDirection + 2) % 4;
	}
	diceY += dy[diceDirection];
	diceX += dx[diceDirection];
	if (diceDirection == 1) {
		int tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	else if (diceDirection == 3) {
		int tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
	else if (diceDirection == 0) {
		int tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	else {
		int tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	if (dice[5] > grid[diceY][diceX]) diceDirection = (diceDirection + 1) % 4;
	else if (dice[5] < grid[diceY][diceX]) diceDirection = (diceDirection + 4 - 1) % 4;
}

void GetScoreContinuous() {
	int ret = 1;

	queue<pii> q;
	int visit[21][21] = { { false, }, };
	q.push({ diceY, diceX });
	visit[diceY][diceX] = true;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny > N || nx > M || ny <= 0 || nx <= 0 || visit[ny][nx] || grid[ny][nx] != grid[y][x]) continue;
			visit[ny][nx] = true;
			q.push({ ny, nx });
			ret++;
		}
	}
	
	score += ret * grid[diceY][diceX];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
		}
	}
	while (K--) {
		RollDice();
		GetScoreContinuous();
	}

	cout << score << '\n';

	return 0;
}