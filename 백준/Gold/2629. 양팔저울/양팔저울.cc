#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, M;
int plumb[31];
bool weight[31][40001];

void dfs(int cur, int wgt) {

    if (cur > N || weight[cur][wgt]) return;
    weight[cur][wgt] = true;
    dfs(cur + 1, wgt + plumb[cur]);
    dfs(cur + 1, abs(wgt - plumb[cur]));
    dfs(cur + 1, wgt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> plumb[i];
    }
    dfs(0, 0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int bead;
        cin >> bead;
        if (weight[N][bead])
            cout << "Y ";
        else
            cout << "N ";
    }

    return 0;
}