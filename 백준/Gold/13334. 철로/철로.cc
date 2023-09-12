#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000007
using namespace std;

int n, d;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= b)
            q.push({ a, b });
        else
            q.push({ b, a });
    }
    cin >> d;

    while (!q.empty()) {
        int l = q.front().first;
        int r = q.front().second;
        q.pop();
        if (r - l > d) continue;
        pq.push({ r - d, -1 });
        pq.push({ l, 1 });
    }
    int ans = 0, cnt = 0;
    while (!pq.empty()) {
        cnt -= pq.top().second;
        ans = max(ans, cnt);
        pq.pop();
    }

    cout << ans << '\n';

    return 0;
}