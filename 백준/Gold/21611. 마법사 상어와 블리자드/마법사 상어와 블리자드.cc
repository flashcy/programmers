#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;

int N, M;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
int grid[50][50];
vector<int> linearGrid;

int ldy[4] = { 0, 1, 0, -1 };
int ldx[4] = { -1, 0, 1, 0 };

int ans = 0;

void blizard(int direction, int range) {
    int idx = 0;
    int factor = 1;
    switch (direction) {
    case 1:
        idx = 7;
        factor = 7;
        break;
    case 2:
        idx = 3;
        factor = 3;
        break;
    case 3:
        idx = 1;
        factor = 1;
        break;
    case 4:
        idx = 5;
        factor = 5;
        break;
    }
    while (range--) {
        if (idx >= linearGrid.size()) return;
        linearGrid.erase(linearGrid.begin() + idx);
        idx--;
        factor += 8;
        idx += factor;
    }
}

void makeLinear(int y, int x, int direction, int range) {
    if (linearGrid.size() >= N * N)return;
    for (int i = 0; i < range; i++) {
        y = y + ldy[direction];
        x = x + ldx[direction];
        if (grid[y][x] == 0) return;
        linearGrid.push_back(grid[y][x]);
    }
    if (direction == 1 || direction == 3) range++;
    makeLinear(y, x, (direction + 1) % 4, range);
}

void makeCircular(int y, int x, int direction, int range, int idx) {
    if (idx >= linearGrid.size())return;
    for (int i = 0; i < range; i++) {
        y = y + ldy[direction];
        x = x + ldx[direction];
        grid[y][x] = linearGrid[idx++];
        if (linearGrid[idx] == 0) return;
    }
    if (direction == 1 || direction == 3) range++;
    makeCircular(y, x, (direction + 1) % 4, range, idx);
}


void bombContinuous() {
    deque<pii> st; // {group, cnt}
    for (int i = 1; i < linearGrid.size(); i++) {
        if (st.empty()) {
            st.push_back({ linearGrid[i], 1 });
            continue;
        }
        if (st.back().first == linearGrid[i]) {
            st.back().second++;
            continue;
        }
        st.push_back({ linearGrid[i], 1 });
    }
    int moreExp = 0;
    linearGrid.resize(0);
    linearGrid.push_back(0);
    for (int i = 0; i < st.size(); i++) {
        if (st[i].second >= 4) {
            ans += st[i].first * st[i].second;
            moreExp++;
            continue;
        }
        for (int j = 0; j < st[i].second; j++) {
            linearGrid.push_back(st[i].first);
        }
    }
    if (moreExp) bombContinuous();
}

void addMarble() {
    deque<pii> dq;
    for (int i = 1; i < linearGrid.size(); i++) {
        if (dq.empty()) {
            dq.push_back({ linearGrid[i], 1 });
            continue;
        }
        if (dq.back().first == linearGrid[i]) {
            dq.back().second++;
            continue;
        }
        dq.push_back({ linearGrid[i], 1 });
    }
    linearGrid.resize(0);
    linearGrid.push_back(0);
    for (int i = 0; i < dq.size(); i++) {
        if (linearGrid.size() >= N * N)break;
        linearGrid.push_back(dq[i].second);
        if (linearGrid.size() >= N * N)break;
        linearGrid.push_back(dq[i].first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    linearGrid.push_back(0);
    makeLinear((N + 1) / 2, (N + 1) / 2, 0, 1);
    while (M--) {
        int d, s;
        cin >> d >> s;
        blizard(d, s);
        bombContinuous();
        addMarble();
    }

    cout << ans << '\n';

    return 0;
}