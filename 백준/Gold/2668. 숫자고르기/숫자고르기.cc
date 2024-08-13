#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N;
int input[101];
bool visit[101];

vector<int> ans;

bool dfs(int start, int cur) {
	if (start == cur) return true;
	if (visit[cur]) return false;
	visit[cur] = true;
	if (dfs(start, input[cur])) {
		ans.push_back(input[cur]);
		return true;
	}
	return visit[cur] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}

	for (int i = 1; i <= N; i++) {
		if (i == input[i]) {
			visit[i] = true;
			ans.push_back(i);
			continue;
		}
		if (visit[i]) continue;
		if (dfs(i, input[i])) {
			ans.push_back(input[i]);
		}
	}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int a : ans) {
		cout << a << '\n';
	}

	return 0;
}