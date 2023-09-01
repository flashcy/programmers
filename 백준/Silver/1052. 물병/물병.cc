#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int N, K;
int bottle[1 << 24];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	int cnt = 0;
	for (int i = (1 << 23); i >= 1; i >>= 1) {
		if (N >= i) {
			N -= i;
			bottle[i]++;
			cnt++;
		}
		if (cnt == K) break;
	}
	if (N > 0) {
		int answer = -1;
		for (int i = 2; i <= (1 << 23); i <<= 1) {
			if (bottle[i] == 0 || N > i) continue;
			answer = i - N;
			break;
		}
		cout << answer << '\n';
	}
	else {
		cout << "0\n";
	}

	return 0;
}