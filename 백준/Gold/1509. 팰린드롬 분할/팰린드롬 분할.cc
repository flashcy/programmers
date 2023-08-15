#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

string input;
bool palindrome[2501][2501];
int dp[2501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    int n = input.size();
    input = ' ' + input;

    // 길이가 1이면 무조건 팰린드롬.
    for (int i = 1; i <= n; i++) {
        palindrome[i][i] = true;
    }
    // 연속 두 개가 같은 문자면 팰린드롬.
    for (int i = 1; i < n; i++) {
        if(input[i] == input[i+1])
            palindrome[i][i+1] = true;
    }
    // 길이가 3부터 n까지 팰린드롬인지 판단.
    for (int i = 3; i <= n; i++) {
        for (int start = 1; start + i - 1 <= n; start++) {
            int end = start + i - 1;
            // 시작과 끝이 같고, 그것보다 길이가 1 짧았을 때도 팰린드롬이면 팰린드롬.
            if (input[start] == input[end] && palindrome[start + 1][end - 1])
                palindrome[start][end] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        // 최대 크기로 초기화 해주고,
        dp[i] = INF;
        for (int j = 1; j <= i; j++) {
            // j부터 i까지 팰린드롬이면, j-1 위치의 dp 값에 1 더한 것과 비교하여 더 작은 값 저장.
            // 자기 자신도 팰린드롬이지만, 앞에 더 큰 팰린드롬이 존재한다면 그 팰린드롬의 길이 + 1이 저장될 것임.
            if (palindrome[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}