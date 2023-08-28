#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define INF 2000000007
using namespace std;

int N, M;
int num[601];
int ans = INF;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void Solve() {
	sort(num, num + N);
	for(int i=0;i<N-3;i++) {
		for (int j = i + 3; j < N; j++) {
			int snow1 = num[j] + num[i]; // 눈사람1 키
			int left = i + 1, right = j - 1;
			while (left < right) {
				int snow2 = num[left] + num[right];
				if (abs(snow1 - snow2) < ans) {
					ans = abs(snow1 - snow2);
					if (ans == 0) {
						cout << "0\n";
						return;
					}
				}
				if (snow1 > snow2) left++;
				else right--;
			}
		}
	}
	cout << ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}