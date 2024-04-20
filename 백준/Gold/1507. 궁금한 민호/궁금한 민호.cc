#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
int grid[21][21];
int fw[21][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int poss = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == k || k == j) continue;
                if (grid[i][k] + grid[k][j] == grid[i][j]) {
                    fw[i][j] = 1;
                }
                else if (grid[i][k] + grid[k][j] < grid[i][j]) {
                    poss = -1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (fw[i][j]) continue;
            ans += grid[i][j];
        }
    }
    if (poss == -1) {
        cout << "-1\n";
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}