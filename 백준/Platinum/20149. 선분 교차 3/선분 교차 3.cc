#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#define pll pair<ll, ll>

typedef long long ll;
using namespace std;

pair<pll, pll> L1, L2;

int ccw(pll p1, pll p2, pll p3) {
    ll S = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
        - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (S > 0) return 1;
    else if (S == 0) return 0;
    else return -1;
}

void getIntersection(pair<pll, pll> l1, pair<pll, pll> l2) {
    double px = (l1.first.first * l1.second.second - l1.first.second * l1.second.first) * (l2.first.first - l2.second.first)
        - (l1.first.first - l1.second.first) * (l2.first.first * l2.second.second - l2.first.second * l2.second.first);
    double py = (l1.first.first * l1.second.second - l1.first.second * l1.second.first) * (l2.first.second - l2.second.second)
        - (l1.first.second - l1.second.second) * (l2.first.first * l2.second.second - l2.first.second * l2.second.first);
    double p = (l1.first.first - l1.second.first) * (l2.first.second - l2.second.second)
        - (l1.first.second - l1.second.second) * (l2.first.first - l2.second.first);

    if (p == 0) {
        if (l1.first == l2.second)
            cout << l1.first.first << " " << l1.first.second;
        else if (l1.second == l2.first)
            cout << l1.second.first << " " << l1.second.second;
        return;
    }

    cout << fixed << setprecision(9) << px / p << " " << py / p;
}

bool isIntersect(pair<pll, pll> l1, pair<pll, pll> l2) {
    pll p1 = l1.first;
    pll p2 = l1.second;
    pll p3 = l2.first;
    pll p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        return (p1 <= p4 && p2 >= p3);
    }
    return (p1p2 <= 0 && p3p4 <= 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    L1 = { {x1, y1}, {x2, y2} };
    cin >> x1 >> y1 >> x2 >> y2;
    L2 = { {x1, y1}, {x2, y2} };

    if (L1.first > L1.second) swap(L1.first, L1.second);
    if (L2.first > L2.second) swap(L2.first, L2.second);

    if (isIntersect(L1, L2)) {
        cout << "1\n";
        getIntersection(L1, L2);
    }
    else {
        cout << "0\n";
    }

    return 0;
}