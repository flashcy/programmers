#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int R, C;
char grid[1001][1001];
queue<pair<pii, int>> q;
queue<pii> f;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'J') {
				q.push({ {i, j}, 0});
			}
			if (grid[i][j] == 'F') {
				f.push({ i, j });
			}
		}
	}
	while (f.size()) {
		q.push({ f.front(), 0 });
		f.pop();
	}

	int ans = 1000000000;
	while (q.size()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		char cur = grid[r][c];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = r + dy[i];
			int nx = c + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
				if (cur == 'J') {
					ans = min(ans, cnt + 1);
				}
				continue;
			}
			if (cur == 'J') {
				if (grid[ny][nx] == '.') {
					q.push({ {ny, nx}, cnt + 1 });
					grid[ny][nx] = 'J';
				}
			}
			else {
				if (grid[ny][nx] == 'J' || grid[ny][nx] == '.') {
					q.push({ {ny, nx}, 0 });
					grid[ny][nx] = 'F';
				}
			}
		}
	}
	if (ans == 1000000000) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << ans << '\n';
	}


	return 0;
}