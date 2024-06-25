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

int N, M;
int jewel[100001];
int cart[100001];
int dp[100001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> jewel[i];
    }
    int sum = 0;
    for (int i = 0; i < M; i++) {
        sum += jewel[i];
    }
    cart[M - 1] = sum;
    dp[M - 1] = sum;
    int ans = sum;
    for (int i = M; i < N; i++) {
        sum += jewel[i] - jewel[i - M];
        cart[i] = sum;
    }
    for (int i = M; i < N; i++) {
        dp[i] = max(dp[i - 1] + jewel[i], cart[i]);
        ans = max(ans, dp[i]);
    }
    cout << max(0, ans);

    return 0;
}