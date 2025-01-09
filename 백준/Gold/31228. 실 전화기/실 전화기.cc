#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;

ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

ll solve(ll n, ll k) {
	if (n % k != 0) {
		if (k > n / 2) k = n - k;
		ll g = gcd(n, k);
		if (g == 1) {
			return n * (k - 1);
		}
		return solve(n / g, k / g);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	

	cout << solve(N, K);

	return 0;
}