#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    long long l = 1, r = K, mid;
    while (l < r) {
        mid = (l + r) / 2;
        long long res = 0;
        for (long long i = 1; i <= N; i++) {
            if ((N * i) < mid) res += N;
            else res += mid / i;
        }
        if (res >= K) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";

    return 0;
}