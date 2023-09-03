#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int N;
pair<pair<int, int>, pair<int, int>> line[101];

int py[4] = { 10, 10, -10, -10 };
int px[4] = { -10, 10, 10, -10 };

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
	if (s > 0) return 1; // 반시계
	else if (s == 0)return 0;
	else return -1;
}

bool isIntersect(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2) {
	pair<int, int> p1 = l1.first;
	pair<int, int> p2 = l1.second;
	pair<int, int> p3 = l2.first;
	pair<int, int> p4 = l2.second;

	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p1 <= p4 && p2 >= p3;
	}
	return p1p2 <= 0 && p3p4 <= 0;
}

pair<int, int> getIntersection(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2) {
	pair<int, int> p1 = l1.first;
	pair<int, int> p2 = l1.second;
	pair<int, int> p3 = l2.first;
	pair<int, int> p4 = l2.second;

	int i = ((p3.first - p4.first) * (p1.first * p2.second - p2.first * p1.second) - (p1.first - p2.first) * (p3.first * p4.second - p3.second * p4.first));
	int j = ((p3.second - p4.second) * (p1.first * p2.second - p2.first * p1.second) - (p1.second - p2.second) * (p3.first * p4.second - p3.second * p4.first));
	int k = ((p1.first - p2.first) * (p3.second - p4.second) - (p3.first - p4.first) * (p1.second - p2.second));

	return { i / k, j / k };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int p1, p2, p3, p4, cnt = 1;
	for (int i = 0; i < N; i++) {
		cin >> p1 >> p2 >> p3 >> p4;
		line[i] = { {p1, p2}, {p3, p4} };
		bool vertex = false, poss = false;
		pair<int, int> ip = {0, 0}, vp = {0, 0};
		for (int k = 0; k < 4; k++) {
			//if (vp.first == px[k] && vp.second == py[k]) continue;
			if (isIntersect(line[i], { {px[k], py[k]}, {px[(k + 1) % 4], py[(k + 1) % 4]} })) {
				ip = getIntersection(line[i], { {px[k], py[k]}, {px[(k + 1) % 4], py[(k + 1) % 4]} });
				if (abs(ip.first) == 10 && abs(ip.second) == 10) {
					if (vertex && vp != ip) {
						poss = true;
						break;
					}
					vertex = true;
					vp = ip;
				}
				else {
					poss = true;
					break;
				}
			}
		}
		if (!poss) {
			i--; N--;
			continue;
		}
		cnt++;
		for (int j = 0; j < i; j++) {
			if (isIntersect(line[i], line[j])) {
				ip = getIntersection(line[i], line[j]);
				if (ip.first >= -10 && ip.first <= 10 && ip.second >= -10 && ip.second <= 10) {
					if (abs(ip.first) == 10 || abs(ip.second) == 10) continue;
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}