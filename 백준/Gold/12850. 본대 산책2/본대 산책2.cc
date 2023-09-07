#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int D;
vector<vector<long long>> map = {
    // 정보, 전산, 미래, 신양, 한경직, 진리, 학회, 형남
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};

vector<vector<long long>> multiply(vector<vector<long long>>& m1, vector<vector<long long>>& m2) {
    vector<vector<long long>> ret(8, vector<long long>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            long long res = 0;
            for (int k = 0; k < 8; k++) {
                res += m1[i][k] * m2[k][j];
                res %= 1000000007;
            }
            ret[i][j] = res % 1000000007;
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> D;
    vector<vector<long long>> ans(8, vector<long long>(8));
    for (int i = 0; i < 8; i++) {
        ans[i][i] = 1;
    }
    vector<vector<long long>> factor = map;
    while (D) {
        if (D & 1) {
            ans = multiply(ans, factor);
            D--;
        }
        factor = multiply(factor, factor);
        D /= 2;
    }
    cout << ans[0][0];

    return 0;
}