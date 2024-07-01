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
int input[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    
    for (int i = 0; i < N; i++) {
        dp[i] = input[i];
        for (int j = 0; j < i; j++) {
            if (input[j] < input[i] && dp[i] < dp[j] + input[i]) {
                dp[i] = dp[j] + input[i];
            }
        }
    }

    cout << *max_element(dp, dp + N) << '\n';

    return 0;
}