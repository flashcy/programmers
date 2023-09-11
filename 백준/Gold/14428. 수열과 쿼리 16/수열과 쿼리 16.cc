#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#define INF 1000000001
#define MOD 1000000007
using namespace std;

int N, M;
int num[1000002];
int tree[3000001];

int Create(int node, int start, int end) {
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int leftIdx = Create(node * 2, start, mid);
	int rightIdx = Create(node * 2 + 1, mid + 1, end);
	if (num[leftIdx] <= num[rightIdx])
		return tree[node] = leftIdx;
	return tree[node] = rightIdx;
}

int Search(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1000001;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int leftIdx = Search(node * 2, start, mid, left, right);
	int rightIdx = Search(node * 2 + 1, mid + 1, end, left, right);
	if (num[leftIdx] <= num[rightIdx])
		return leftIdx;
	return rightIdx;
}

int Modify(int node, int start, int end, int target) {
	if (start > target || end < target) return tree[node];
	if (start == end) {
		if (start == target)
			tree[node] = target;
		return tree[node];
	}
	int mid = (start + end) / 2;
	int leftIdx = Modify(node * 2, start, mid, target);
	int rightIdx = Modify(node * 2 + 1, mid + 1, end, target);
	if (num[leftIdx] <= num[rightIdx])
		return tree[node] = leftIdx;
	return tree[node] = rightIdx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	Create(1, 0, N - 1);
	num[1000001] = INF;
	cin >> M;
	for (int i = 0; i < M; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			num[b] = c;
			Modify(1, 0, N - 1, b);
		}
		else {
			b--; c--;
			cout << Search(1, 0, N - 1, b, c) + 1 << '\n';
		}
	}

	return 0;
}