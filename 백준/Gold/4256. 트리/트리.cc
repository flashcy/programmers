#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;

int T;
int q1[1001];
int q2[1001];
int tree[10001];
stack<int> st;

void find(int l, int r, int idx, int node) {
    if (l == r) {
        //tree[node] = q1[idx];
        st.push(q1[idx]);
        return;
    }
    for (int i = l; i <= r; i++) {
        if (q1[idx] == q2[i]) {
            //tree[node] = q2[i];
            st.push(q2[i]);
            find(i + 1, r, idx + i - l + 1, node * 2 + 1);
            find(l, i - 1, idx + 1, node * 2);
            return;
        }
    }
}
/*
void print(int node) {
    if (tree[node] == 0) return;
    print(node * 2);
    print(node * 2 + 1);
    cout << tree[node] << ' ';
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        //memset(tree, 0, sizeof(tree));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> q1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> q2[i];
        }
        find(0, n - 1, 0, 1);
        while (st.size()) {
            cout << st.top() << ' ';
            st.pop();
        }
        //print(1);
        cout << '\n';
    }

    return 0;
}