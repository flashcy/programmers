#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000007
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll ans[10];

void calc(ll n, int digit) {
    while (n) {
        ans[n % 10] += digit;
        n /= 10;
    }
}

void solve(ll n, int digit) {
    while (n % 10 != 9 && n > 0) {
        calc(n, digit);
        n--;
    }
    if (n > 0) {
        for (int i = 0; i < 10; i++) {
            ans[i] += (n / 10 + 1) * digit;
            if (i == 0)ans[i] -= digit;
        }
        solve(n / 10, digit * 10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    solve(n, 1);
    //if (ans[0])ans[0]--;
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}