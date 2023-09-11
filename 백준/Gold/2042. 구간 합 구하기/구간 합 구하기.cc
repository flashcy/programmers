#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#define INF 100000000
using namespace std;

int N, M, K;
long long num[1000001];
long long tree[3000001];

long long Create(int node, int start, int end) {
	if (start == end)
		return tree[node] = num[start];
	int mid = (start + end) / 2;
	return tree[node] = Create(node * 2, start, mid) + Create(node * 2 + 1, mid + 1, end);
}

long long Search(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return Search(node * 2, start, mid, left, right) + Search(node * 2 + 1, mid + 1, end, left, right);
}

void Modify(int node, int start, int end, int target, long long dif) {
	if (start > target || end < target) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	Modify(node * 2, start, mid, target, dif);
	Modify(node * 2 + 1, mid + 1, end, target, dif);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> num[i];
	Create(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			long long dif = c - num[b];
			num[b] = c;
			Modify(1, 0, N - 1, b, dif);
		}
		else {
			b--; c--;
			cout << Search(1, 0, N - 1, b, c) << '\n';
		}
	}

	return 0;
}