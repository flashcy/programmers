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
		line[i] = { a,b };
	}
	memset(repIdx, -2, sizeof(repIdx));
	sort(line, line + N);

	A.push_back(line[0]);
	repIdx[0] = 0;
	for (int i = 1; i < N; i++) {
		if (A.back().second < line[i].second) {
			A.push_back(line[i]);
			repIdx[i] = A.size() - 1;
		}
		else if (A.back().second > line[i].second) {
			int l = 0, r = A.size() - 1;
			while (l < r) {
				int mid = (l + r) / 2;
				if (A[mid].second >= line[i].second) {
					r = mid;
				}
				else l = mid + 1;
			}
			A[r] = line[i];
			repIdx[i] = r;
		}
	}

	int idx = A.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (repIdx[i] == idx) {
			idx--;
		}
		else {
			ans.push_back(line[i].first);
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a << "\n";
	}

	return 0;
}