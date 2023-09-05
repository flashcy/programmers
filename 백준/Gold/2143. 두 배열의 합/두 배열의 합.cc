#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int n, m;
long long A[1001], B[1001];
long long T, ans = 0;
map<long long, long long> cnt;
vector<long long> sumA, sumB;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];

	for (int i = 0; i < n; i++) {
		long long sum = A[i];
		sumA.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = B[i];
		sumB.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			sumB.push_back(sum);
		}
	}

	sort(sumB.begin(), sumB.end());

	for (int i = 0; i < sumA.size(); i++) {
		if (!cnt.insert({ sumA[i], 0 }).second) {
			ans += cnt[sumA[i]];
			continue;
		}
		long long ret = 0;
		long long target = T - sumA[i];
		int left = 0, right = sumB.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (sumB[mid] >= target) right = mid;
			else left = mid + 1;
		}
		while (right < sumB.size() && sumB[right] == target) {
			ret++;
			right++;
		}
		cnt[sumA[i]] = ret;
		ans += ret;
	}

	cout << ans;
	return 0;
}