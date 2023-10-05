#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

deque<int> input[4];

void dfs(int cur, int dir, int lr) {
	// lr : 1이면 우측으로, -1이면 좌측으로.
	if (cur + lr >= 0 && cur + lr < 4) {
		if (input[cur][4 - 2 * lr] != input[cur + lr][4 + 2 * lr]) {
			dfs(cur + lr, -dir, lr);
			if (dir == 1) {
				input[cur + lr].push_front(input[cur + lr].back());
				input[cur + lr].pop_back();
			}
			else {
				input[cur + lr].push_back(input[cur + lr].front());
				input[cur + lr].pop_front();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			input[i].push_back(c - '0');
		}
	}
	int K;
	cin >> K;
	while (K--) {
		int n, d;
		cin >> n >> d;
		n--;
		dfs(n, -d, -1);
		dfs(n, -d, 1);
		if (d == 1) {
			input[n].push_front(input[n].back());
			input[n].pop_back();
		}
		else {
			input[n].push_back(input[n].front());
			input[n].pop_front();
		}
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		answer += input[i][0] * pow(2, i);
	}
	cout << answer;
}