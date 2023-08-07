#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int board[51][51];
int visit[51][51];
int dp[51][51];
queue<pair<int, pair<int, int>>> q; //{y, x}

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int answer = 0;

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * board[y][x];
        int nx = x + dx[i] * board[y][x];
        if (ny >= 0 && ny < N && nx >= 0 && nx < M && board[ny][nx] != 0) {
            if (visit[ny][nx] != 0) {
                cout << "-1\n";
                exit(0);
            }
            if (dp[ny][nx] < dp[y][x] + 1) {
                visit[ny][nx] = 1;
                dp[ny][nx] = dp[y][x] + 1;
                dfs(ny, nx);
                visit[ny][nx] = 0;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'H') {
                board[i][j] = 0;
            }
            else {
                board[i][j] = c - '0';
            }
        }
    }

    visit[0][0] = 1;
    dfs(0, 0);
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer + 1 << "\n";

    return 0;
}