#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, H;
int tomato[101][101][101];
queue<tuple<int, int, int>> q;
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { -1, 0, 1, 0, 0, 0 }; // 시계방향 이동
int dz[6] = { 0, 0, 0, 0, -1, 1 }; // 위/아래 이동

void BFS();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> tomato[h][i][j];

                if (tomato[h][i][j] == 1) {
                    q.push(make_tuple(h, i, j));
                    // 익은 토마토 좌표 저장
                }
            }
        }
    }
    BFS();

    int day = 0;
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (tomato[h][i][j] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
                day = max(day, tomato[h][i][j]);
            }
        }
    }

    cout << day - 1 << "\n";
    return 0;
}

void BFS() {
    while (!q.empty()) {
        int currX = get<2>(q.front());
        int currY = get<1>(q.front());
        int currZ = get<0>(q.front());
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            int newZ = currZ + dz[i];

            if (newX < 0 || newX >= M || newY < 0 || newY >= N || newZ < 0 || newZ >= H)
                continue;
            if (tomato[newZ][newY][newX] == 0) {
                tomato[newZ][newY][newX] = tomato[currZ][currY][currX] + 1;
                q.push(make_tuple(newZ, newY, newX));
            }
        }
    }
}