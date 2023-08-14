#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define MAX 100000000

using namespace std;

int N, M, T;
int map[101][101];
int visit[101][101];

queue<pair<int, pair<int, int>>> q;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    int ans = MAX;
    visit[0][0] = 1;
    q.push({ 0,{0,0} });
    while (!q.empty()) {
        int cnt = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if (y == N - 1 && x == M - 1) {
            ans = min(ans, cnt);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= N || ny < 0 || nx >= M || nx < 0 || map[ny][nx] == 1 || visit[ny][nx] == 1)continue;

            if (map[ny][nx] == 2) {
                visit[ny][nx] = 1;
                ans = min(ans, cnt + (N - ny - 1) + (M - nx - 1) + 1);
            }
            else {
                visit[ny][nx] = 1;
                q.push({ cnt + 1, {ny, nx} });
            }
        }
    }

    if (ans == MAX || ans > T) {
        cout << "Fail\n";
    }
    else {
        cout << ans << "\n";
    }

    return 0;
}