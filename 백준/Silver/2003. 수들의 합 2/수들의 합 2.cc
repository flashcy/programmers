#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, M;
long long num[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    int i = 0, j = 0, cnt = 0;
    long long sum = 0;
    while (i < N && j < N) {
        sum += num[j];
        j++;
        while (sum >= M) {
            if (sum == M) cnt++;
            sum -= num[i];
            i++;
        }
    }
    cout << cnt << "\n";

    return 0;
}