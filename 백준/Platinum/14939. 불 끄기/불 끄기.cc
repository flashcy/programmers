#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 100000000

using namespace std;

bool map[11][11];
bool copyMap[11][11];
int cnt = 0, answer = INF;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void turn(int y, int x) {
    copyMap[y][x] = !copyMap[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10) {
            copyMap[ny][nx] = !copyMap[ny][nx];
        }
    }
}

bool isPossible() {
    // 현재 위치 기준 위의 전구가 켜져있으면 turn.
    // 아래로 내려가는 탐색이기에, 위에 켜져있는데 turn 안하면 그 전구는 끌 수가 없음.
    for (int y = 1; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (copyMap[y - 1][x]) {
                cnt++;
                turn(y, x);
            }
        }
    }

    // 가장 아래 열에서 켜져있는 전구가 있으면 fail
    for (int x = 0; x < 10; x++) {
        if (copyMap[9][x]) {
            return false;
        }
    }
    return true;
}

void solve() {
    // 첫 줄 다 눌러보기
    for (int i = 0; i < 1024; i++) {
        for (int row = 0; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                copyMap[row][col] = map[row][col];
            }
        }

        cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                cnt++;
                turn(0, j);
            }
        }

        if (isPossible()) answer = min(answer, cnt);
    }
    if (answer == INF) {
        cout << "-1\n";
    }
    else {
        cout << answer << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            if (c == 'O') map[i][j] = true;
        }
    }


    solve();

    return 0;
}