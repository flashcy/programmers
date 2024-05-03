#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int N, K;
vector<double> points;
int area[1001];
int idx[1001];
int ans = 1000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	points.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i];
	}
	sort(points.begin(), points.end());
	double divider = 360.0L / K;
	for (int i = 0; i < N; i++) {
		idx[0] = 0;
		for (int j = 1; j < K; j++) {
			double target = divider * (double)j + points[0] - 0.0001;
			int left = 0, right = N - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (points[mid] < target) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			if (points[left] > target) left--;
			idx[j] = left;
		}
		area[0] = idx[1] + 1;
		for (int j = 2; j < K; j++) {
			area[j - 1] = idx[j] - idx[j - 1];
		}
		area[K - 1] = N - idx[K - 1] - 1;
		ans = min(ans, *max_element(area, area + K) - *min_element(area, area + K));
		points.push_back(points[0] + 360.0L);
		points.erase(points.begin(), points.begin() + 1);
	}
	cout << ans << '\n';
	return 0;
}