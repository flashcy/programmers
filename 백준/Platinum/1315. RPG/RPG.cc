#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <cstring>
#define INF 100000000

using namespace std;

int N;
pair<pair<int, int>,int> pnt[50];
int dp[1002][1002];
bool visit[50];


int dfs(int s, int i) {
    if (dp[s][i] != -1)
        return dp[s][i];

    dp[s][i] = 0;
    vector<int> q;
    int p = 0;
    for (int n = 0; n < N; n++) {
        if (pnt[n].first.first <= s || pnt[n].first.second <= i) {
            dp[s][i]++;
            if (!visit[n]) {
                p += pnt[n].second;
                q.push_back(n);
                visit[n] = true;
            }
        }
    }

    for (int sp = 0; sp <= p; sp++) {
        int nS = min(1000, s + sp);
        int nI = min(1000, i + p - sp);
        dp[s][i] = max(dp[s][i], dfs(nS, nI));
    }

    for (int k : q)
        visit[k] = false;

    return dp[s][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int s, i, p;
    for (int n = 0; n < N; n++) {
        cin >> s >> i >> p;
        pnt[n] = { {s, i}, p };
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1);

    return 0;
}