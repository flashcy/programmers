#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define MOD 1000000007
using namespace std;

int N, num[3];
long long sol[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sol[i];
	}
	sort(sol, sol + N);
	long long ans = 3000000001;
	for (int k = 0; k < N; k++) {
		int i = 0, j = N - 1;
		while (i < j) {
			if (k == i) {
				i++;
				continue;
			}
			if (k == j) {
				j--;
				continue;
			}
			if (abs(sol[i] + sol[j] + sol[k]) < ans) {
				ans = abs(sol[i] + sol[j] + sol[k]);
				num[0] = sol[i];
				num[1] = sol[j];
				num[2] = sol[k];
				if (ans == 0)break;
			}
			if (sol[i] + sol[j] + sol[k] > 0) j--;
			else i++;
		}
	}
	sort(num, num + 3);
	cout << num[0] << " " << num[1] << " " << num[2] << "\n";

	return 0;
}