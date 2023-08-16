#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

int N;
int ans = -1;
int minValue[11];
int board[22][22];

void MoveTo(int dir) {
    if (dir == 0) {
        // 위로 가자!
        for (int col = 0; col < N; col++) {
            int value = -1;
            int idx = -1;
            for (int row = 0; row < N; row++) {
                if (board[row][col] == 0) continue;
                if (board[row][col] == value) {
                    board[idx][col] = board[idx][col] * 2;
                    value = -1;
                }
                else {
                    value = board[row][col];
                    idx++;
                    board[idx][col] = board[row][col];
                }
            }
            for (int row = idx + 1; row < N; row++) {
                board[row][col] = 0;
            }
        }
    }
    // 우
    else if (dir == 1) {
        for (int row = 0; row < N; row++) {
            int value = -1;
            int idx = N;
            for (int col = N - 1; col >= 0; col--) {
                if (board[row][col] == 0) continue;
                if (board[row][col] == value) {
                    board[row][idx] = board[row][idx] * 2;
                    value = -1;
                }
                else {
                    value = board[row][col];
                    idx--;
                    board[row][idx] = board[row][col];
                }
            }
            for (int col = idx - 1; col >= 0; col--) {
                board[row][col] = 0;
            }
        }
    }
    // 하
    else if (dir == 2) {
        for (int col = 0; col < N; col++) {
            int value = -1;
            int idx = N;
            for (int row = N - 1; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                if (board[row][col] == value) {
                    board[idx][col] = board[idx][col] * 2;
                    value = -1;
                }
                else {
                    value = board[row][col];
                    idx--;
                    board[idx][col] = board[row][col];
                }
            }
            for (int row = idx - 1; row >= 0; row--) {
                board[row][col] = 0;
            }
        }
    }
    // 좌
    else if (dir == 3) {
        for (int row = 0; row < N; row++) {
            int value = -1;
            int idx = -1;
            for (int col = 0; col < N; col++) {
                if (board[row][col] == 0) continue;
                if (board[row][col] == value) {
                    board[row][idx] = board[row][idx] * 2;
                    value = -1;
                }
                else {
                    value = board[row][col];
                    idx++;
                    board[row][idx] = board[row][col];
                }
            }
            for (int col = idx + 1; col < N; col++) {
                board[row][col] = 0;
            }
        }
    }
    return;
}

int getMax() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret = max(ret, board[i][j]);
        }
    }
    return ret;
}

void comb(int cnt) {
    if (cnt == 10) {
        ans = max(ans, getMax());
        return;
    }
    // 이미 나온 최댓값에 도달할 수 없을때,
    if (getMax() * (1 << (10 - cnt)) <= ans) return;
    int now[22][22];
    memcpy(now, board, sizeof now);
    for (int i = 0; i < 4; i++) {
        MoveTo(i);
        int flag = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (board[j][k] != now[j][k]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) comb(cnt + 1);
        memcpy(board, now, sizeof board);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            ans = max(ans, board[i][j]);
        }
    }
    //MoveTo(MoveTo(MoveTo(MoveTo(MoveTo(board, 0), 1), 1), 0), 1);
    comb(0);
    std::cout << ans << "\n";

    return 0;
}