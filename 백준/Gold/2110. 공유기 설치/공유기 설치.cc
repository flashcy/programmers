#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;

int N, C;
int x[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> x[i];
    sort(x, x + N);

    int ans = 0;
    int l = 1, r = x[N - 1] - x[0];
    while (l <= r) {
        int cnt = 1, tmp = x[0];
        int mid = (l + r) / 2;
        for (int i = 1; i < N; i++) {
            if (x[i] - tmp >= mid) {
                tmp = x[i];
                cnt++;
            }
        }
        if (cnt < C) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
            ans = mid;
        }
    }

    cout << ans;

    return 0;
}