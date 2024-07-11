#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N;
int fav[404][4];

int seat[21][21];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int answer = 0;

void Find(int idx) {
	// { 인접한 위치의 친한 친구 수, {빈 자리, {행, 열}}}
	priority_queue<pair<int, pair<int, pii>>> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (seat[i][j]) continue;
			int friendCount = 0, blank = 0;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (y >= N || x >= N || y < 0 || x < 0)continue;
				if (seat[y][x]) {
					for (int l = 0; l < 4; l++) {
						if (fav[idx][l] == seat[y][x])
							friendCount++;
					}
				}
				else {
					blank++;
				}
			}
			pq.push({ friendCount, {blank, {-i, -j}} });
		}
	}
	seat[-pq.top().second.second.first][-pq.top().second.second.second] = idx;
}

void GetScore() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int friendCount = 0, idx = seat[i][j];
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (y >= N || x >= N || y < 0 || x < 0)continue;
				for (int l = 0; l < 4; l++) {
					if (fav[idx][l] == seat[y][x])
						friendCount++;
				}
			}
			answer += pow(10, friendCount - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	queue<int> seq;
	for (int i = 0; i < N * N; i++) {
		int idx;
		cin >> idx;
		seq.push(idx);
		for (int j = 0; j < 4; j++) {
			cin >> fav[idx][j];
		}
	}

	while (seq.size()) {
		int idx = seq.front();
		seq.pop();
		Find(idx);
	}
	GetScore();

	cout << answer;

	return 0;
}