#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, pair<int, int>>> q;
int visit[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S;
    cin >> S;

    q.push({ 1, {0, 0} });
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second.first;
        int clip = q.front().second.second;
        q.pop();
        if (cur > 1000) continue;
        if (cur == S) {
            cout << cnt << "\n";
            break;
        }
        if (clip > 0) {
            q.push({ cur + clip, {cnt + 1, clip} }); // 붙여넣기.
        }
        if (visit[cur] > 0 || (cur == 0 && clip == 0)) continue;
        visit[cur] = 1;
        q.push({ cur, {cnt + 1, cur} });
        q.push({ cur - 1, {cnt + 1, clip} });
    }


    return 0;
}