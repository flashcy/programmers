#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int K;
		cin >> K;
		int ans1 = -1, ans2 = -1;
		int alphabet[26] = { 0, };
		queue<int> q[26]; //K개가 되는 가장 앞 위치 저장
		for (int i = 0; i < str.size(); i++) {
			int idx = str[i] - 'a';
			alphabet[idx]++;
			q[idx].push(i);
			if (alphabet[idx] == K) {
				if (ans1 == -1)
					ans1 = i - q[idx].front() + 1;
				else
					ans1 = min(ans1, i - q[idx].front() + 1);
				ans2 = max(ans2, i - q[idx].front() + 1);
				q[idx].pop();
			}
			if (alphabet[idx] > K) {
				ans1 = min(ans1, i - q[idx].front() + 1);
				ans2 = max(ans2, i - q[idx].front() + 1);
				q[idx].pop();
			}
		}
		if (ans1 == -1)
			cout << "-1\n";
		else {
			cout << ans1 << ' ' << ans2 << '\n';
		}
	}

	return 0;
}