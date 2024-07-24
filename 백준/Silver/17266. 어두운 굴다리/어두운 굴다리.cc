#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int coord[100002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> coord[i];
	int diff = max(coord[1], N - coord[M]);
	for (int i = 2; i <= M; i++) {
		diff = max(diff, (coord[i] - coord[i - 1] + 1) / 2);
	}
	cout << diff;

	return 0;
}