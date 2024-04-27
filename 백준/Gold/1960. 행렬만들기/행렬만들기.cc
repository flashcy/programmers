#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
int row[501];
priority_queue<pii> col;
int ans[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> row[i];
    }
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        col.push({ c, i });
    }

    for (int i = 0; i < N; i++) {
        vector<pii> tmp;
        for (int j = 0; j < row[i]; j++) {
            pii cur = col.top();
            col.pop();
            if (ans[i][cur.second]) {
                tmp.push_back(cur);
                j--;
                continue;
            }
            ans[i][cur.second] = 1;
            cur.first--;
            col.push(cur);
        }
        while (tmp.size()) {
            col.push(tmp[tmp.size() - 1]);
            tmp.pop_back();
        }
    }
    int poss = 1;
    while (col.size()) {
        if (col.top().first != 0) {
            poss = -1;
            break;
        }
        col.pop();
    }
    cout << poss << '\n';
    if (poss != -1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}