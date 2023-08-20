#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define INF 100000000

using namespace std;

int T, n, m, t, s, g, h;
vector<pair<int, int>> edges[2001];
int arrival[101];
int dist[3][2001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;

void dijkstra(int st, int gh) {
    dist[gh][st] = 0;
    pq.push({ 0, st });
    while (!pq.empty()) {
        int d = pq.top().first;
        int s = pq.top().second;
        pq.pop();

        if (dist[gh][s] < d) continue;

        for (auto edge : edges[s]) {
            int next = edge.first;
            if (edge.second + d < dist[gh][next]) {
                dist[gh][next] = edge.second + d;
                pq.push({ dist[gh][next], next });
            }
        }
    }
}

void Solve() {
    dist[0][h] = 0;
    dist[1][g] = 0;
    dijkstra(g, 0);
    dijkstra(h, 1);
    dijkstra(s, 2);

    int gh = 0;
    for (auto i : edges[g]) {
        if (i.first == h) {
            gh = i.second;
            break;
        }
    }

    for (int i = 0; i < t; i++) {
        if (dist[0][arrival[i]] + dist[1][s] + gh == dist[2][arrival[i]] ||
            dist[1][arrival[i]] + dist[0][s] + gh == dist[2][arrival[i]])
            continue;
        arrival[i] = 0;
    }

    sort(arrival, arrival + t);
    for (int i = 0; i < t; i++) {
        if (arrival[i])
            cout << arrival[i] << ' ';
    }
    cout << '\n';
}

void Input() {
    cin >> n >> m >> t >> s >> g >> h;
    for (int i = 1; i <= n; i++) {
        edges[i].clear();
        dist[0][i] = INF;
        dist[1][i] = INF;
        dist[2][i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back({ b, d });
        edges[b].push_back({ a, d });
    }
    for (int i = 0; i < t; i++) {
        cin >> arrival[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        Input();
        Solve();
    }

    return 0;
}