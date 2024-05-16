#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;

int N, D;
deque<pil> dq;
ll ans = -1e14;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        pil cache;
        cache.first = i;
        cin >> cache.second;

        while (dq.size() && dq.front().first < i - D)
            dq.pop_front();
        if (dq.size())
            cache.second = max(cache.second, dq.front().second + cache.second);
        while (dq.size() && dq.back().second <= cache.second)
            dq.pop_back();

        ans = max(ans, cache.second);
        dq.push_back(cache);
    }
    cout << ans << '\n';

    return 0;
}