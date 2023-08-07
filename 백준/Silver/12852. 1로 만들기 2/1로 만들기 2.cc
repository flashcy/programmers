#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, string>> q;
bool dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string ans;

    q.push({ N, to_string(N) });
    while (!q.empty()) {
        int cur = q.front().first;
        ans = q.front().second;
        q.pop();
        if (cur == 1)break;
        if (dp[cur]) continue;
        dp[cur] = true;
        if (cur % 3 == 0) {
            q.push({ cur / 3, ans + " " + to_string(cur / 3) });
        }
        if (cur % 2 == 0) {
            q.push({ cur / 2, ans + " " + to_string(cur / 2) });
        }
        if (cur > 1) {
            q.push({ cur - 1, ans + " " + to_string(cur - 1) });
        }
    }

    int cnt = 0;
    for (char c : ans) {
        if (c == ' ') cnt++;
    }
    cout << cnt << "\n" << ans << "\n";

    return 0;
}