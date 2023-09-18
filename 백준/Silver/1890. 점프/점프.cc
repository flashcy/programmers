#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int N;
ll dp[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ll k;
			cin >> k;
			if (i == N - 1 && j == N - 1)continue;
			if (j + k < N && dp[i][j])
				dp[i][j + k] += dp[i][j];
			if (i + k < N && dp[i][j])
				dp[i + k][j] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1];
	return 0;
}