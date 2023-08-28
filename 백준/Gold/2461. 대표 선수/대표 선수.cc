#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define INF 2000000007
using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> pq[1001];
int stu[1001];
int ans = INF;

int findMin() {
	int temp = stu[0];
	int ret = 0;
	for (int i = 1; i < N; i++) {
		if (temp > stu[i]) {
			temp = stu[i];
			ret = i;
		}
	}
	return ret;
}

int findMax() {
	int temp = stu[0];
	int ret = 0;
	for (int i = 1; i < N; i++) {
		if (temp < stu[i]) {
			temp = stu[i];
			ret = i;
		}
	}
	return ret;
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			pq[i].push(input);
		}
	}
}

void Solve() {
	for (int i = 0; i < N; i++) {
		stu[i] = pq[i].top();
		pq[i].pop();
	}
	int minIdx = findMin(), maxIdx = findMax();
	ans = stu[maxIdx] - stu[minIdx];
	while (!pq[minIdx].empty()) {
		stu[minIdx] = pq[minIdx].top();
		pq[minIdx].pop();
		if (stu[minIdx] > stu[maxIdx]) maxIdx = minIdx;
		minIdx = findMin();
		ans = min(ans, stu[maxIdx] - stu[minIdx]);
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