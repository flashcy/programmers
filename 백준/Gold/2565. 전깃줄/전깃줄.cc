#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int N;
pair<int, int> line[100001];
vector<int> A;
vector<int> ans;

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

	A.push_back(line[0].second);
	for (int i = 1; i < N; i++) {
		if (A.back() < line[i].second) {
			A.push_back(line[i].second);
		}
		else {
			int left = 0, right = A.size() - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (A[mid] >= line[i].second) right = mid;
				else left = mid + 1;
			}
			A[right] = line[i].second;
		}
	}

	cout << N - A.size() << '\n';

	return 0;
}