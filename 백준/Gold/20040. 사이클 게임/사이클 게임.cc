#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

int N, M;
int par[500001];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool uni(int u, int v) {
    int par_u = find(par[u]);
    int par_v = find(par[v]);
    if (par_u == par_v) return true;
    par[par_u] = par_v;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        par[i] = i;
    }

    int cnt = 0;
    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        if (uni(u, v)) {
            cnt = i + 1;
            break;
        }
    }

    cout << cnt << "\n";

    return 0;
}