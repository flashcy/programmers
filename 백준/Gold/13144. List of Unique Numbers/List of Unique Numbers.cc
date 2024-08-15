#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll N;
map<ll, int> nums;

ll sum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 100000; i++) {
		sum[i] = i + sum[i - 1];
	}
	cin >> N;

	int l = 1, r = 0;
	int midIndex = -1; // midIndex는 현재까지 경우의 수에 포함된 인덱스

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		if (nums[input]) {
			if (l <= nums[input] && nums[input] <= r) {
				ans += sum[r - l + 1];
				if (midIndex >= l) {
					ans -= sum[midIndex - l + 1];
				}
				midIndex = r;
				l = nums[input] + 1;
			}
		}
		nums[input] = i;
		r++;
	}
	ans += sum[r - l + 1];
	if (midIndex >= l) {
		ans -= sum[midIndex - l + 1];
	}
	cout << ans << '\n';

	/*
	map에 저장된 인덱스가 투 포인터 사이에 있다면
	현재 구간 내 수들의 경우의 수 - 이전에 포함된 적 없는 수들의 경우의 수
	*/



	return 0;
}