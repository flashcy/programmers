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

int length, width, height;
int N;
pii cube[21]; // 한 변의 길이가 2^a인 큐브 b개

int ans = 0;
bool isFail = false;

void Solve(int l, int w, int h, int idx) {
    if (l == 0 || w == 0 || h == 0) return;

    for (int i = idx; i >= 0; i--) {
        if (cube[i].second == 0) continue;

        int mag = cube[i].first;
        if (mag > l || mag > w || mag > h) continue;

        cube[i].second--;
        ans++;

        Solve(l - mag, w, h, i);
        Solve(mag, w - mag, h, i);
        Solve(mag, mag, h - mag, i);

        return;
    }
    isFail = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> length >> width >> height;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cube[i] = { (1 << a), b };
    }

    Solve(length, width, height, N - 1);
    cout << (isFail ? -1 : ans) << '\n';

    return 0;
}