#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, M;
pair<pair<int, int>, int> edges[6001];
long long dist[501];

bool bell_ford(int st) {
    dist[st] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s = edges[j].first.first;
            if (dist[s] == INF) continue;
            int d = edges[j].first.second;
            int w = edges[j].second;
            if (dist[s] + w < dist[d]) {
                if (i == N - 1) return false;
                dist[d] = dist[s] + w;
            }
        }
    }
    return true;
}

void Solve() {
    if (!bell_ford(1)) {
        cout << "-1\n";
    }
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << '\n';
        }
    }
}

void Input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edges[i] = { {s, d}, w };
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
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