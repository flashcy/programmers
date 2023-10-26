#include <iostream>	
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

typedef long long ll;
int N;
vector<int> A;
int input[1000002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	//vector<int> repIdx(N, -2);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	A.push_back(input[0]);
	//repIdx[0] = 0;
	for (int i = 1; i < N; i++) {
		if (A.back() < input[i]) {
			A.push_back(input[i]);
			//repIdx[i] = A.size() - 1;
			continue;
		}
		int left = 0, right = A.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (A[mid] >= input[i]) right = mid;
			else left = mid + 1;
		}
		A[right] = input[i];
		//repIdx[i] = right;
	}
	cout << A.size() << '\n';
	/*
	stack<int> st;
	int idx = A.size() - 1;
	for (int i = 0; i < N; i++) {
		if (repIdx[N - i - 1] == idx) {
			st.push(input[N - i - 1]);
			idx--;
		}
	}
	while (st.size()) {
		cout << st.top() << ' ';
		st.pop();
	}
	*/
}