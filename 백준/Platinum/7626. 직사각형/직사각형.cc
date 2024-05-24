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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;

typedef struct vertex {
    int x;
    pii y;
    bool start;
} vertex;

int N;
vector<int> ylist;
vector<vertex> verties;

ll tree[1600010];
ll cnt[1600010];

void update(int node, int s, int e, int l, int r, int v) {
    if (s > r || e < l) return;
    if (l <= s && e <= r) {
        cnt[node] += v;
    }
    else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r, v);
        update(node * 2 + 1, mid + 1, e, l, r, v);
    }

    if (cnt[node]) {
        tree[node] = (ll)ylist[e] - ylist[s - 1];
    }
    else {
        if (s == e)tree[node] = 0;
        else tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        verties.push_back({ x1, {y1 + 1, y2 + 1}, true });
        verties.push_back({ x2, {y1 + 1, y2 + 1}, false });
        ylist.push_back(y1 + 1);
        ylist.push_back(y2 + 1);
    }
    sort(ylist.begin(), ylist.end());
    ylist.erase(unique(ylist.begin(), ylist.end()), ylist.end());
    sort(verties.begin(), verties.end(), [](vertex& a, vertex& b) {return a.x < b.x; });

    ll ans = 0;
    ll diff_x = 0;
    for (int i = 0; i < verties.size(); i++) {
        if (i > 0) {
            diff_x = verties[i].x - verties[i - 1].x;
            ans += diff_x * tree[1];
        }
        int val = verties[i].start == true ? 1 : -1;
        int y1 = lower_bound(ylist.begin(), ylist.end(), verties[i].y.first) - ylist.begin();
        int y2 = lower_bound(ylist.begin(), ylist.end(), verties[i].y.second) - ylist.begin();
        update(1, 1, ylist.size(), y1 + 1, y2, val);
    }
    cout << ans << '\n';

    return 0;
}