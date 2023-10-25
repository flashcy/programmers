#include <iostream>	
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

typedef long long ll;
int N;
stack<pair<ll, ll>> st;
ll answer = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		if (n == 0) {
			while (st.size()) {
				answer = max(answer, st.top().first * (i - st.top().second));
				st.pop();
			}
			continue;
		}
		if (st.empty() || st.top().first <= n) {
			st.push({ n, i });
			continue;
		}
		ll tmpIdx = i;
		while (!st.empty() && st.top().first > n) {
			answer = max(answer, st.top().first * (i - st.top().second));
			tmpIdx = min(tmpIdx, st.top().second);
			st.pop();
		}
		st.push({ n, tmpIdx });
	}
	while (!st.empty()) {
		answer = max(answer, st.top().first * (N - st.top().second));
		st.pop();
	}
	cout << answer;
}