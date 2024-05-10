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

int N, M, K;
int table[1001][1001];
int visit[1001][1001];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == '1')
                table[i][j] = 1;
        }
    }

    memset(visit, -1, sizeof(visit));

    // { {이동 횟수, 부순 벽 수}, {y, x} }
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;
    pq.push({ {1, 0}, {0, 0} });
    visit[0][0] = 0;

    int ans = -1;

    while (pq.size()) {
        int cnt = pq.top().first.first;
        int k = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if (y == N - 1 && x == M - 1) {
            ans = cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            if (table[ny][nx]) {
                if (k + 1 > K)continue;
                if (visit[ny][nx] > -1 && visit[ny][nx] <= k + 1)continue;
                visit[ny][nx] = k + 1;
                pq.push({ {cnt + (cnt % 2 == 0) + 1, k + 1}, {ny, nx} });
            }
            else {
                if (visit[ny][nx] > -1 && visit[ny][nx] <= k)continue;
                visit[ny][nx] = k;
                pq.push({ {cnt + 1, k}, {ny,nx} });
            }
        }
    }
    cout << ans << '\n';

    return 0;
}