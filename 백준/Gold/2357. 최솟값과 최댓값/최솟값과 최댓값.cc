#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 1000000007
using namespace std;

int N, M;
int num[100001];
pair<int, int> segtree[1001002];

pair<int, int> CreateTree(int left, int right, int node) {
    if (left == right) {
        return segtree[node] = { num[left], num[left]};
    }
    int mid = (left + right) / 2;
    pair<int, int> leftNode = CreateTree(left, mid, node * 2);
    pair<int, int> rightNode = CreateTree(mid + 1, right, node * 2 + 1);
    segtree[node].first = min(leftNode.first, rightNode.first);
    segtree[node].second = max(leftNode.second, rightNode.second);
    return segtree[node];
}

pair<int, int> FindNode(int left, int right, int node, int start, int end) {
    if (start > right || end < left) return { INF, -INF };
    if (start <= left && right <= end) return segtree[node];
    int mid = (left + right) / 2;
    pair<int, int> leftNode = FindNode(left, mid, node * 2, start, end);
    pair<int, int> rightNode = FindNode(mid + 1, right, node * 2 + 1, start, end);
    pair<int, int> ret = { INF, -INF };
    ret.first = min(leftNode.first, rightNode.first);
    ret.second = max(leftNode.second, rightNode.second);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> num[i];
    CreateTree(0, N - 1, 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> node = FindNode(0, N - 1, 1, a - 1, b - 1);
        cout << node.first << ' ' << node.second << '\n';
    }

    return 0;
}