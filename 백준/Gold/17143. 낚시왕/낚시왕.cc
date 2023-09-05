#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

typedef struct Shark {
	int y;
	int x;
	int spd;
	int dir;
	int sz;
	bool isDead = false;
} S;

int R, C, M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int sharkMap[101][101];
vector<S> sharks;

void moveShark() {
	queue<pair<pair<int, int>, S>> next;
	for (int i = 1; i < sharks.size(); i++) {
		S& shark = sharks[i];
		if (shark.isDead) continue;
		sharkMap[shark.y][shark.x] = 0;
		if (shark.dir == 0) {
			int move = shark.y - shark.spd;
			if (move <= 0) {
				move = -move;
				if ((move / (R - 1)) % 2 == 0) {
					shark.dir = 1;
					shark.y = (move % (R - 1));
				}
				else {
					shark.y = (R - 1) - (move % (R - 1));
				}
			}
			else {
				shark.y -= shark.spd;
			}
		}
		else if (shark.dir == 1) {
			int move = shark.y + shark.spd;
			if (move >= R - 1) {
				move -= R - 1;
				if ((move / (R - 1)) % 2 == 0) {
					shark.dir = 0;
					shark.y = (R - 1) - (move % (R - 1));
				}
				else {
					shark.y = (move % (R - 1));
				}
			}
			else {
				shark.y += shark.spd;
			}
		}
		if (shark.dir == 3) {
			int move = shark.x - shark.spd;
			if (move <= 0) {
				move = -move;
				if ((move / (C - 1)) % 2 == 0) {
					shark.dir = 2;
					shark.x = (move % (C - 1));
				}
				else {
					shark.x = (C - 1) - (move % (C - 1));
				}
			}
			else {
				shark.x -= shark.spd;
			}
		}
		else if (shark.dir == 2) {
			int move = shark.x + shark.spd;
			if (move >= C - 1) {
				move -= C - 1;
				if ((move / (C - 1)) % 2 == 0) {
					shark.dir = 3;
					shark.x = (C - 1) - (move % (C - 1));
				}
				else {
					shark.x = (move % (C - 1));
				}
			}
			else {
				shark.x += shark.spd;
			}
		}
	}
	for (int i = 1; i < sharks.size(); i++) {
		S& shark = sharks[i];
		if (shark.isDead) continue;
		if (sharkMap[shark.y][shark.x] > 0) {
			if (sharks[sharkMap[shark.y][shark.x]].sz > shark.sz) {
				shark.isDead = true;
				continue;
			}
			else {
				sharks[sharkMap[shark.y][shark.x]].isDead = true;
			}
		}
		sharkMap[shark.y][shark.x] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sharks.push_back(S());

	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharkMap[r - 1][c - 1] = i;
		sharks.push_back({ r - 1, c - 1, s, d - 1, z });
	}

	int cnt = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (sharkMap[j][i] > 0) {
				cnt += sharks[sharkMap[j][i]].sz;
				sharks[sharkMap[j][i]].isDead = true;
				sharkMap[j][i] = 0;
				break;
			}
		}
		moveShark();
	}

	cout << cnt;

	return 0;
}