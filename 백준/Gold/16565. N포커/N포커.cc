#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int nCk[53][53];
const int MOD = 10007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i <= 52; i++) {
		nCk[i][0] = 1; nCk[i][i] = 1;
		for (int j = 1; j < i; j++) {
			nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
			nCk[i][j] %= MOD;
		}
	}
	int ans = 0;
	for (int i = 4; i <= N; i+=4) {
		if ((i / 4) % 2 == 1) {
			ans = (ans + nCk[13][i / 4] * nCk[52 - i][N - i]) % MOD;
		}
		else {
			ans = (ans - (nCk[13][i / 4] * nCk[52 - i][N - i]) % MOD + MOD) % MOD;
		}
	}
	cout << ans << '\n';

	return 0;
}