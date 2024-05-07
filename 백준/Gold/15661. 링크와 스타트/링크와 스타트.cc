#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int table[21][21];

bool t1[21];
int ans = 1000000000;

void comb(int idx, int cnt) {
    if (idx == N)return;
    if (cnt > (N + 1) / 2)return;

    if (cnt > 0) {
        int t1_s = 0, t2_s = 0;
        for (int i = 0; i < N; i++) {
            if (t1[i]) {
                for (int j = i + 1; j < N; j++) {
                    if (t1[j]) {
                        t1_s += table[i][j] + table[j][i];
                    }
                }
            }
            if (!t1[i]) {
                for (int j = i + 1; j < N; j++) {
                    if (!t1[j]) {
                        t2_s += table[i][j] + table[j][i];
                    }
                }
            }
        }
        ans = min(ans, abs(t1_s - t2_s));
    }


    t1[idx] = true;
    comb(idx + 1, cnt + 1);
    t1[idx] = false;
    comb(idx + 1, cnt);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }

    comb(0, 0);
    cout << ans << '\n';

    return 0;
}