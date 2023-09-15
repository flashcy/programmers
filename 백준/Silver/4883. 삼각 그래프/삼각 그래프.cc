#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int vertex[100001][3];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, k = 1;
    cin >> N;
    while (N) {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[0][0] = b;
        vertex[0][1] = b;
        vertex[0][2] = b + c;
        for (int i = 1; i < N; i++) {
            cin >> a >> b >> c;
            vertex[i][0] = min(vertex[i - 1][0], vertex[i - 1][1]) + a;
            vertex[i][1] = min(min(vertex[i - 1][0], vertex[i - 1][1]), min(vertex[i - 1][2], vertex[i][0])) + b;
            vertex[i][2] = min(min(vertex[i - 1][1], vertex[i - 1][2]), vertex[i][1]) + c;
        }
        cout << k << ". " << vertex[N - 1][1] << '\n';
        // new TC
        cin >> N;
        k++;
    }

    return 0;
}