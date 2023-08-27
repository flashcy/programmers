#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, d, k, c;
int sushi[3000001];
int sel[3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
        sushi[i]--;
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        if(sel[sushi[i]] == 0) res++;
        sel[sushi[i]]++;
    }
    if (sel[c - 1] == 0) {
        res++;
    }
    int ans = res;
    for (int i = 0; i < N; i++) {
        // 빠진 게 쿠폰이면,
        if (sushi[i] == c - 1 && sel[c - 1] == 1) {
            res++;
        }
        if (--sel[sushi[i]] == 0) res--;

        int j = (i + k) % N;
        // 새로 들어온 게 쿠폰이면,
        if (sushi[j] == c - 1 && sel[c - 1] == 0) {
            res--;
        }
        if(sel[sushi[j]]++ == 0) res++;
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}