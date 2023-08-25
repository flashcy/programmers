#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define INF 1000000007
using namespace std;

int N;
long long p[1000002];
//int mat[502][502], s[502][502];
//
//void matOrder() {
//	for (int leng = 1; leng < N; leng++) {
//		for (int i = 1; i <= N - leng; i++) {
//			int j = i + leng;
//			mat[i][j] = INF;
//			for (int k = i; k < j; k++) {
//				if (mat[i][j] > mat[i][k] + mat[k + 1][j] + p[i - 1] * p[j] * p[k]) {
//					mat[i][j] = mat[i][k] + mat[k + 1][j] + p[i - 1] * p[j] * p[k];
//					s[i][j] = k;
//				}
//			}
//		}
//	}
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> p[0];
	for (int i = 1; i < N; i++) {
		int t;
		cin >> t >> p[i];
	}
	cin >> p[N];

	//for (int i = 0; i < N; i++) {
	//	mat[i][i] = 0;
	//}
	//matOrder();

	long long ans = 0;
	for (int i = N; i >= 2; i--) {
		ans += p[N] * p[i - 1] * p[i - 2];
	}

	cout << ans;

	return 0;
}