#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000007
using namespace std;

int N;
vector<int> child[1000001];
int dp[1000001][2];
bool visit[1000001];

void dfs(int u) {
    visit[u] = true;
    dp[u][0] = 1;
    for (auto v : child[u]) {
        if (visit[v]) continue;
        dfs(v);
        dp[u][1] += dp[v][0]; // 부모가 일반인이라면 자식은 무조건 얼리어답터여야함.
        dp[u][0] += min(dp[v][0], dp[v][1]); // 부모가 얼리어답터면 최적해를 찾아 더함.
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        child[u].push_back(v);
        child[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}