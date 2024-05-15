#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, B;
vector<vector<ll>> matrix;
const ll MOD = 1000;

vector<vector<ll>> mul(vector<vector<ll>>& m1, vector<vector<ll>>& m2) {
    vector<vector<ll>> ret(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ret[i][j] += (m1[i][k] * m2[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vector<ll>> div(vector<vector<ll>>& m, ll b) {
    if (b == 1) return m;
    vector<vector<ll>> x = div(m, b / 2);
    x = mul(x, x);
    if (b % 2 == 1) {
        x = mul(x, m);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> B;
    matrix.resize(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<ll>> ans = div(matrix, B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] % MOD << ' ';
        }
        cout << '\n';
    }

    return 0;
}