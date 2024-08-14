#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int N;
stack<pii> st;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		while (st.size() && st.top().second >= y) {
			if (st.top().second > y) ans++;
			st.pop();
		}
		if (y == 0)continue;
		st.push({ x, y });
	}
	cout << ans + st.size();

	return 0;
}