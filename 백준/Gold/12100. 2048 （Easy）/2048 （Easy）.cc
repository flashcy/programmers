#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

int N;

vector<vector<int>> MoveTo(vector<vector<int>> board, int dir) {
    if (dir == 0) {
        for (int col = 0; col < N; col++) {
            for (int row = 0; row < N; row++) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveUp = row;
                while (moveUp > 0) {
                    if (board[moveUp - 1][col] > 0) break;
                    moveUp--;
                }
                board[moveUp][col] = value;
            }
            for (int row = 1; row < N; row++) {
                if (board[row][col] == board[row - 1][col]) {
                    board[row][col] = 0;
                    board[row - 1][col] *= 2;
                }
            }
            for (int row = 0; row < N; row++) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveUp = row;
                while (moveUp > 0) {
                    if (board[moveUp - 1][col] > 0) break;
                    moveUp--;
                }
                board[moveUp][col] = value;
            }
        }
    }
    else if (dir == 1) {
        for (int row = 0; row < N; row++) {
            for (int col = N - 1; col >= 0; col--) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveRight = col;
                while (moveRight < N - 1) {
                    if (board[row][moveRight + 1] > 0) break;
                    moveRight++;
                }
                board[row][moveRight] = value;
            }
            for (int col = N - 2; col >= 0; col--) {
                if (board[row][col] == board[row][col + 1]) {
                    board[row][col] = 0;
                    board[row][col + 1] *= 2;
                }
            }
            for (int col = N - 1; col >= 0; col--) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveRight = col;
                while (moveRight < N - 1) {
                    if (board[row][moveRight + 1] > 0) break;
                    moveRight++;
                }
                board[row][moveRight] = value;
            }
        }
    }
    else if (dir == 2) {
        for (int col = 0; col < N; col++) {
            for (int row = N - 1; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveDown = row;
                while (moveDown < N - 1) {
                    if (board[moveDown + 1][col] > 0) break;
                    moveDown++;
                }
                board[moveDown][col] = value;
            }
            for (int row = N - 2; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                if (board[row][col] == board[row + 1][col]) {
                    board[row][col] = 0;
                    board[row + 1][col] *= 2;
                }
            }
            for (int row = N - 1; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveDown = row;
                while (moveDown < N - 1) {
                    if (board[moveDown + 1][col] > 0) break;
                    moveDown++;
                }
                board[moveDown][col] = value;
            }
        }
    }
    else if (dir == 3) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveLeft = col;
                while (moveLeft > 0) {
                    if (board[row][moveLeft - 1] > 0) break;
                    moveLeft--;
                }
                board[row][moveLeft] = value;
            }
            for (int col = 1; col < N; col++) {
                if (board[row][col] == 0) continue;
                if (board[row][col] == board[row][col - 1]) {
                    board[row][col] = 0;
                    board[row][col - 1] *= 2;
                }
            }
            for (int col = 0; col < N; col++) {
                if (board[row][col] == 0) continue;
                int value = board[row][col];
                board[row][col] = 0;
                int moveLeft = col;
                while (moveLeft > 0) {
                    if (board[row][moveLeft - 1] > 0) break;
                    moveLeft--;
                }
                board[row][moveLeft] = value;
            }
        }
    }
    return board;
}

int comb(vector<vector<int>> board, int cnt) {
    int result = 0;
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = max(result, board[i][j]);
            }
        }
        return result;
    }
    for (int i = 0; i < 4; i++) {
        result = max(result, comb(MoveTo(board, i), cnt + 1));
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> board;
    board.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            board[i].push_back(input);
        }
    }
    //MoveTo(MoveTo(MoveTo(MoveTo(MoveTo(board, 0), 1), 1), 0), 1);
    cout << comb(board, 0);

    return 0;
}