#include <iostream>
#include <algorithm>
#include <map>
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

int N, M;
pii meat[100001];

bool compare(const pii& a, const pii& b) {
	if (a.first == b.first) {
		return a.second > b.second;   //내림차순
	}
	else return a.first < b.first;    //오름차순
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int sum = 0, idx = 0, ans = 2147483647;
	for (int i = 0; i < N; i++) {
		cin >> meat[i].second >> meat[i].first;
	}
	sort(meat, meat + N, compare);
	// 무게에 대해서 정렬하고,
	// 더 비싼거 나올때까지 summation,
	// 나왔는데 무게 안 채워졌으면 reset
	// 무게 채워졌으면 그게 답
	int cur = 0, price = 0;
	for (int i = 0; i < N; i++) {
		sum += meat[i].second;
		if (meat[i].first > cur) {
			if (sum >= M) {
				ans = meat[i].first;
				break;
			}
			else {
				price = meat[i].first;
				cur = meat[i].first;
				continue;
			}
		}
		cur = meat[i].first;
		price += meat[i].first;
		if (sum >= M) {
			ans = min(ans, price);
		}
	}
	if (sum < M)
		ans = -1;
	cout << ans;

	return 0;
}