#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int N;
pair<int, int> line[100001];
vector<pair<int, int>> A;
vector<int> ans;
int repIdx[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		line[i] = { a, b };
	}
	sort(line, line + N);

	A.push_back(line[0]);
	repIdx[0] = 0;
	for (int i = 1; i < N; i++) {
		if (A.back().second < line[i].second) {
			A.push_back(line[i]);
			repIdx[i] = A.size() - 1;
		}
		else {
			int left = 0, right = A.size() - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (A[mid].second >= line[i].second) right = mid;
				else left = mid + 1;
			}
			A[right] = line[i];
			repIdx[i] = right;
		}
	}

	int idx = A.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (idx == repIdx[i]) idx--;
		else ans.push_back(line[i].first);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto a : ans) {
		cout << a << '\n';
	}

	return 0;
}