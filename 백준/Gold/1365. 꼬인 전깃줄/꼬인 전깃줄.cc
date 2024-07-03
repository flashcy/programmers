#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;

int N;
int x[100001];
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> x[i];

    A.push_back(x[0]);
    for (int i = 1; i < N; i++) {
        if (A.back() < x[i]) A.push_back(x[i]);
        else {
            int l = 0, r = A.size() - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (A[m] > x[i])
                    r = m;
                else
                    l = m + 1;
            }
            A[l] = x[i];
        }
    }
    cout << N - A.size() << '\n';

    return 0;
}