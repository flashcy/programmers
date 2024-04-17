#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int N;
int n[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    sort(n, n + N);
    int i = 0, j = N - 1;
    int sum = 2100000000;
    pii ans = { 0, 100000 };
    while (i < j) {
        if (abs(n[i] + n[j]) < sum) {
            ans = { i, j };
            sum = abs(n[i] + n[j]);
            if (sum == 0) break;
        }
        if (n[i] + n[j] > 0) j--;
        else i++;

    }
    cout << n[ans.first] << ' ' << n[ans.second];

    return 0;
}