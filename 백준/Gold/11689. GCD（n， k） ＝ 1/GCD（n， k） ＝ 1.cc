#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

long long n;
vector<long long> factors;

void findFactor() {
    long long p;
    long long num = n;

    for (p = 2; p * p <= num; p++) {
        if (num % p == 0) {
            factors.push_back(p);
        }

        while (num % p == 0) {
            num /= p;
        }
    }

    // root(n) 보다 큰 소수 남은 것.
    // 혹은 n이 prime.
    if (num > 1)
        factors.push_back(num);
}

void euler() {
    // n == 1
    if (n == 1) {
        cout << 1;
        return;
    }
    
    // n is a prime number
    if (factors[0] == n) {
        cout << n - 1;
        return;
    }

    // else.
    long long ans = n;
    for (auto p : factors) {
        ans /= p;
        ans *= p - 1;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    findFactor();
    euler();

    return 0;
}