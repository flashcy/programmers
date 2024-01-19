#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
int M, N, K;
ll factorial[4000001];
const ll MOD = 1000000007;

ll Power(int exp, int base) {
	if (exp == 1) return base;
	ll ret = Power(exp / 2, base);
	if (exp % 2 == 1) {
		return ((ret * ret) % MOD * base) % MOD;
	}
	return (ret * ret) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M;
	factorial[0] = 1;
	for (int i = 1; i <= 4000000; i++) {
		factorial[i] = (i * factorial[i - 1]) % MOD;
	}
	while (M--) {
		cin >> N >> K;
		cout << (factorial[N] * Power(MOD - 2, (factorial[K] * factorial[N - K]) % MOD)) % MOD << '\n';
	}
	return 0;
}