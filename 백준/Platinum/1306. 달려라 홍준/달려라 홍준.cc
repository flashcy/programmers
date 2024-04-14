#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int N, M;
int light[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> light[i];
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < 2 * M - 1; i++) {
        pq.push({ -light[i], i });
    }
    cout << -pq.top().first << ' ';
    for (int i = 2 * M - 1; i < N; i++) {
        pq.push({ -light[i], i });
        while (pq.size() && pq.top().second < i - 2 * M + 2)
            pq.pop();
        cout << -pq.top().first << ' ';
    }

    return 0;
}