#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define INF 2000000007
using namespace std;

int N, M;
int num[100001];
int ans = INF;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void Solve() {
	sort(num, num + N);
	int i = 0, j = 1;
	while (i < N && j < N) {
		int dif = num[j] - num[i];
		if (dif >= M) {
			ans = min(ans, dif);
			i++;
			continue;
		}
		j++;
	}
	cout << ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}