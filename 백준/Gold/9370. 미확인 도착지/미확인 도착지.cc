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
int dist[3][2001]; // [0]: g -> others without h, [1]: h -> others without g, [2]: s -> others
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
    // g -> h 미리 최솟값으로 만들어둠.
    dist[0][h] = 0;

    // h -> g 미리 최솟값으로 만들어둠.
    dist[1][g] = 0;

    // 위의 작업을 하는 이유는 최단경로 구할 때 g - h 경로로 최단경로 찾는 걸 방지하기 위함.
    // 추후에 따로 더해줄거라.
    dijkstra(g, 0);
    dijkstra(h, 1);
    dijkstra(s, 2);

    // g - h 거리 찾기
    int gh = 0;
    for (auto i : edges[g]) {
        if (i.first == h) {
            gh = i.second;
            break;
        }
    }

    for (int i = 0; i < t; i++) {
        // s -> 도착지 후보까지의 경로가
        // s -> g -> h -> 도착지 후보 or s-> h -> g -> 도착지 후보 중에 있다면,
        // 해당 도착지 후보는 도착지 가능.
        if (dist[0][arrival[i]] + dist[1][s] + gh == dist[2][arrival[i]] ||
            dist[1][arrival[i]] + dist[0][s] + gh == dist[2][arrival[i]])
            continue;
        // 그러나 g -> h 혹은 h -> g를 거치지 않는 최단거리라면, 도착지 불가능.
        arrival[i] = 0;
    }

    // 도착지를 오름차순 정렬 후 출력.
    sort(arrival, arrival + t);
    for (int i = 0; i < t; i++) {
        if (arrival[i]) // 안 되는 도착지는 0으로 바꿨기에 걸러짐.
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
    while (T--) {
        Input();
        Solve();
    }

    return 0;
}