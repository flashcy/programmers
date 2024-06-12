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

ll N, P, Q;
map<ll, ll> m;

ll infiniteSequence(ll i) {
    if (i == 0) return 1;
    if (m[i])
        return m[i];
    return m[i] = infiniteSequence(i / P) + infiniteSequence(i / Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> P >> Q;
    cout << infiniteSequence(N);

    return 0;
}