#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#define INF 1000000000
using namespace std;

int N;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, int>> planet;

//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int par[100001];
int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

bool uni(int u, int v) {
    int par_u = find(par[u]);
    int par_v = find(par[v]);
    if (par_u == par_v) return false;
    par[par_u] = par_v;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back({ x, i });
        Y.push_back({ y, i });
        Z.push_back({ z, i });
        par[i] = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N - 1; i++) {
        planet.push_back({ X[i + 1].first - X[i].first, X[i].second, X[i + 1].second });
        planet.push_back({ Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second });
        planet.push_back({ Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second });
    }
    sort(planet.begin(), planet.end());

    int ans = 0;
    for (int i = 0; i < planet.size(); i++) {
        int dist = get<0>(planet[i]);
        int source = get<1>(planet[i]);
        int dest = get<2>(planet[i]);

        if (uni(source, dest)) ans += dist;
    }

    cout << ans << "\n";

    return 0;
}