#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> segTree;
// 두 노드 중 최댓값을 부모 노드의 value로 저장
// 현재 노드의 value보다 target이 작거나 같으면 탐색 더 진행

int findNode(int node, int start, int end, int target) {
	if (start == end)return start;
	int mid = (start + end) / 2;
	if (segTree[node * 2] >= target) return findNode(node * 2, start, mid, target);
	return findNode(node * 2 + 1, mid + 1, end, target - segTree[node * 2]);
}

void updateNode(int node, int start, int end, int target, int diff) {
	if (target < start || target > end) return;
	segTree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		updateNode(node * 2, start, mid, target, diff);
		updateNode(node * 2 + 1, mid + 1, end, target, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int treeHeight = (int)ceil(log2(1000000));
	int treeSize = 1 << (treeHeight + 1);
	segTree.resize(treeSize);

	int n;
	cin >> n;
	while (n--) {
		int A, B, C;
		cin >> A >> B;
		if (A == 2) {
			cin >> C;
			updateNode(1, 1, 1000000, B, C);
		}
		else {
			int ret = findNode(1, 1, 1000000, B);
			cout << ret << '\n';
			updateNode(1, 1, 1000000, ret, -1);
		}
	}

	return 0;
}