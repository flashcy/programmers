#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int board[11][11];

int dy[4] = { -1, 1, 1, -1 };
int dx[4] = { 1, 1, -1, -1 };

// black board
vector<pair<int, int>> b_bishop;
pair<int, int> b_sel[100];

// white board
vector<pair<int, int>> w_bishop;
pair<int, int> w_sel[100];
int b_ans = 0, w_ans = 0;

bool b_place(int y, int x, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int sy = b_sel[i].first;
        int sx = b_sel[i].second;
        if (abs(y - sy) == abs(x - sx)) return false;
    }
    return true;
}

bool w_place(int y, int x, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int sy = w_sel[i].first;
        int sx = w_sel[i].second;
        if (abs(y - sy) == abs(x - sx)) return false;
    }
    return true;
}

void b_dfs(int cnt, int cur) {
    //int now[11][11];
    //memcpy(now, board, sizeof now);
    if (cur == b_bishop.size()) {
        b_ans = max(b_ans, cnt);
        return;
    }

    b_sel[cnt] = b_bishop[cur];

    if (b_place(b_bishop[cur].first, b_bishop[cur].second, cnt)) {
        b_dfs(cnt + 1, cur + 1);
        //memcpy(board, now, sizeof board);
    }
    b_dfs(cnt, cur + 1);
}

void w_dfs(int cnt, int cur) {
    //int now[11][11];
    //memcpy(now, board, sizeof now);
    if (cur == w_bishop.size()) {
        w_ans = max(w_ans, cnt);
        return;
    }

    w_sel[cnt] = w_bishop[cur];

    if (w_place(w_bishop[cur].first, w_bishop[cur].second, cnt)) {
        w_dfs(cnt + 1, cur + 1);
        //memcpy(board, now, sizeof board);
    }
    w_dfs(cnt, cur + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                if ((i + j) % 2 == 0)
                    w_bishop.push_back({ i, j });
                else
                    b_bishop.push_back({ i, j });
            }
        }
    }

    b_dfs(0, 0);
    w_dfs(0, 0);

    cout << b_ans + w_ans << "\n";

    return 0;
}