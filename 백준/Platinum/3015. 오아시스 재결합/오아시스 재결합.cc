#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int N;
long long people[500001];
stack<pair<long long, long long>> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		int sameHeight = 1;
		while (!st.empty() && st.top().first < people[i]) {
			cnt += st.top().second;
			st.pop();
		}
		if (!st.empty()){
			if (st.top().first == people[i]) {
				cnt += st.top().second;
				sameHeight = st.top().second + 1;
				if (st.size() > 1)
					cnt++;
				st.pop();
			}
			else {
				cnt++;
			}
		}
		st.push({ people[i], sameHeight });
	}
	cout << cnt;
	return 0;
}