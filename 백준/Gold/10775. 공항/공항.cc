#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
bool dock[100001];
int par[100001];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void uni(int a, int b) {
    int parA = find(a);
    int parB = find(b);
    if (parA == parB) return;
    par[parA] = par[parB];
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int cnt = 0;
    for (int i = 1; i <= N; i++)par[i] = i;
    bool poss = true;
    for (int i = 0; i < M; i++) {
        int input;
        cin >> input;
        if (!poss)continue;
        int target = find(input);
        if (target == 0) poss = false;
        else {
            cnt++;
            uni(target, target - 1);
        }
    }
    cout << cnt;
    return 0;
}