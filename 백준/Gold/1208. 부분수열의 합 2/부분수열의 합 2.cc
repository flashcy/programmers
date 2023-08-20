#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, S;
int num[40];
map<int, int> sum;
long long answer = 0;

void rSum(int cur, int s) {
    if (cur == N) {
        sum[s]++;
        return;
    }

    rSum(cur + 1, s + num[cur]);
    rSum(cur + 1, s);
}
void lSum(int cur, int s) {
    if (cur == N / 2) {
        answer += sum[S - s];
        return;
    }

    lSum(cur + 1, s + num[cur]);
    lSum(cur + 1, s);
}

void Solve() {
    rSum(N / 2, 0);
    lSum(0, 0);

    if (!S) cout << answer - 1;
    else cout << answer;
}

void Input() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    Input();
    Solve();

    return 0;
}