#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	ll p, q;
	ll num;
	Point(ll x = 0, ll y = 0, ll n = 0) : x(x), y(y), p(1), q(0), num(n) {}
};

bool comp(const Point& A, const Point& B) {
	if (1LL * A.p * B.q != 1LL * A.q * B.p)
		return 1LL * A.p * B.q > 1LL * A.q * B.p;
	if (A.y != B.y)
		return A.y < B.y;
	return A.x < B.x;
}

ll ccw(const Point& A, const Point& B, const Point& C) {
	return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

Point p[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			ll x, y;
			cin >> x >> y;
			p[i] = Point(x, y, i);
		}
		sort(p, p + N, comp);
		for (int i = 1; i < N; i++) {
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p + 1, p + N, comp);
		int pt = N - 1;
		for (int i = N - 1; i >= 1; i--) {
			if (ccw(p[0], p[i], p[i - 1]) == 0)
				pt--;
			else
				break;
		}
		for (int i = 0; i < pt; i++) {
			cout << p[i].num << ' ';
		}
		for (int i = N - 1; i >= pt; i--) {
			cout << p[i].num << ' ';
		}

		cout << '\n';
	}
	/*stack<int> st;
	st.push(0);
	st.push(1);
	int next = 2;
	while (next < N) {
		while (st.size() >= 2) {
			int second = st.top();
			st.pop();
			int first = st.top();
			if (ccw(p[first], p[second], p[next]) > 0) {
				st.push(second);
				break;
			}
		}
		st.push(next++);
	}
	cout << st.size();*/

	return 0;
}