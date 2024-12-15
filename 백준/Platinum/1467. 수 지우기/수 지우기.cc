#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int digit[10];
int input[1005];
int inputSize;

int delDigit[10];
int del[1005];
int delSize;

int temp[10];
int output[1006];

bool isPoss() {
	for (int i = 0; i < 10; i++) {
		if (temp[i] > delDigit[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 1005; i++) {
		char c;
		c = cin.get();
		if (c == '\n') break;
		input[i] = c - '0';
		digit[input[i]]++;
		inputSize = i + 1;
	}

	for (int i = 0; i < inputSize; i++) {
		char c;
		c = cin.get();
		if (c == '\n') break;
		del[i] = c - '0';
		digit[del[i]]--;
		delDigit[del[i]]++;
		delSize = i + 1;
	}

	int pos = 0;
	int idx = 0;
	for (int i = 0; i < inputSize - delSize; i++) {
		for (int j = 9; j >= 0; j--) {
			if (digit[j] == 0)continue;

			memset(temp, 0, sizeof(temp));
			for (int k = pos; input[k] != j; k++) temp[input[k]]++;

			if (isPoss()) {
				while (input[pos] != j) {
					delDigit[input[pos]]--;
					pos++;
				}
				output[idx++] = j;
				digit[j]--;
				pos++;

				break;
			}
		}
	}

	for (int i = 0; i < idx; i++) {
		cout << output[i];
	}

	return 0;
}