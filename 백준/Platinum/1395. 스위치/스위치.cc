#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
bool lazy[400001];
int tree[400001];

void lazyUpdate(int node, int left, int right) {
    if (lazy[node]) {
        tree[node] = (right - left + 1) - tree[node];
        if (left != right) {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        lazy[node] = false;
    }
}

int findNode(int node, int left, int right, int start, int end) {
    lazyUpdate(node, left, right);
    if (start > right || end < left) return 0;
    if (start <= left && right <= end) return tree[node];
    int mid = (left + right) / 2;
    return findNode(node * 2, left, mid, start, end)
        + findNode(node * 2 + 1, mid + 1, right, start, end);
}

void updateNode(int node, int left, int right, int start, int end) {
    lazyUpdate(node, left, right);
    if (start > right || end < left) return;
    if (start <= left && right <= end) {
        tree[node] = (right - left + 1) - tree[node];
        if (left != right) {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return;
    }
    int mid = (left + right) / 2;
    updateNode(node * 2, left, mid, start, end);
    updateNode(node * 2 + 1, mid + 1, right, start, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    while (M--) {
        int q, s, t;
        cin >> q >> s >> t;
        if (q == 0) {
            updateNode(1, 0, N - 1, s - 1, t - 1);
        }
        else {
            cout << findNode(1, 0, N - 1, s - 1, t - 1) << '\n';
        }
    }

    return 0;
}