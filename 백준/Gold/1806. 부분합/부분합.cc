#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 1000000001
using namespace std;

int N, S;
int input[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    int start = 0, end = 0;
    int k = 0;
    while (end < N) {
        k += input[end];
        if (k >= S) {
            while (k >= S) {
                ans = min(ans, end - start + 1);
                k -= input[start];
                start++;
            }
        }
        end++;
    }
    if (ans == INF)
        cout << "0\n";
    else
        cout << ans << "\n";

    return 0;
}