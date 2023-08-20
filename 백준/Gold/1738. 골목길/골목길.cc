#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, M;
pair<pair<int, int>, int> edges[20001];
vector<int> chk_cycle[101];
pair<long long, int> dist[101];
stack<int> route;
bool visit[101];
int cycleNode;

void bell_ford(int st) {
    dist[st] = { 0, st };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s = edges[j].first.first;
            if (dist[s].first == INF) continue;
            int d = edges[j].first.second;
            int w = edges[j].second;
            if (dist[s].first + w < dist[d].first) {
                if (i == N - 1) {
                    cycleNode = s;
                    return;
                }
                dist[d].first = dist[s].first + w;
                dist[d].second = s;
            }
        }
    }
}

void dfs(int cur) {
    if (visit[cur]) return;
    visit[cur] = true;
    for (int i : chk_cycle[cur]) {
        dfs(i);
    }
}

void Solve() {
    bell_ford(1);
    dfs(cycleNode);
    int cur = N;
    while (cur != 1 && !visit[cur]) {
        visit[cur] = true;
        route.push(cur);
        cur = dist[cur].second;
    }
    if (cur == 1) {
        cout << cur << ' ';
        while (!route.empty()) {
            cout << route.top() << ' ';
            route.pop();
        }
    }
    else {
        cout << "-1\n";
    }
}

void Input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edges[i] = { {s, d}, -w };
        chk_cycle[s].push_back(d);
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = { INF, INF };
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}