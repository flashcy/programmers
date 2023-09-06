#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int map[1001][1001];
int visit[1001][1001];
int cnt = 1;

int dfs(int y, int x, int num) {
    int dir = map[y][x];
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (ny >= N || nx >= M || ny < 0 || nx < 0 || visit[ny][nx]) {
        if (visit[ny][nx] == num) {
            cnt++;
        }
        else {
            visit[y][x] = visit[ny][nx];
        }
        return visit[y][x];
    }
    visit[ny][nx] = num;
    return visit[y][x] = dfs(ny, nx, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'U') map[i][j] = 0;
            else if (c == 'R') map[i][j] = 1;
            else if (c == 'D') map[i][j] = 2;
            else if (c == 'L') map[i][j] = 3;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j]) continue;
            visit[i][j] = cnt;
            dfs(i, j, cnt);
        }
    }
    cout << cnt - 1;
    return 0;
}