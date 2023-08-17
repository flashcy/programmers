#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define MAX 100000000

using namespace std;

int N, M, K;
int minsu[4000001];
bool selected[4000001];
int cheolsu[10001];

int BiSearch(int k) {
    int l = 0, r = M - 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if (minsu[mid] >= k)
            r = mid;
        else l = mid + 1;
    }
    if (minsu[r] == k) r++;
    while (selected[minsu[r]]) {
        r++;
    }
    selected[minsu[r]] = true;
    return minsu[r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> minsu[i];
    }
    sort(minsu, minsu + M);
    for (int i = 0; i < K; i++) {
        int input;
        cin >> input;
        cout << BiSearch(input) << "\n";
    }


    return 0;
}