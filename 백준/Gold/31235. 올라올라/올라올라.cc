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

int N;
int A[1000001];
stack<pii> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)cin >> A[i];
	int ans = 0;

	for (int i = 0; i < N; i++) {
		while (st.size() && st.top().first <= A[i]) {
			ans = max(ans, i - st.top().second);
			st.pop();
		}
		st.push({ A[i], i });
	}
	while (st.size()) {
		ans = max(ans, N - st.top().second);
		st.pop();
	}
	if (ans == 0) ans = N;
	cout << ans;

	return 0;
}