#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int preBuilt[1001];
int spend[1001];
vector<int> build[1001];

queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // input
        int N, K, W;
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> spend[i];
            //init.
            build[i].clear();
            preBuilt[i] = 0;
        }
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            build[x].push_back(y);
        }
        cin >> W;

        // logic
        for (int i = 1; i <= N; i++) {
            if (preBuilt[i] == 0) {
                q.push({ i, spend[i] });
            }
            preBuilt[i] = 0;
        }
        int ans = 0;
        while (!q.empty()) {
            int cur = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (cnt < preBuilt[cur]) continue;

            if (cur == W) {
                ans = cnt;
            }


            for (int i = 0; i < build[cur].size(); i++) {
                int next = build[cur][i];
                if (preBuilt[next] < cnt + spend[next]) {
                    preBuilt[next] = cnt + spend[next];
                    q.push({ next, preBuilt[next] });
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}