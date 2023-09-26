#include <string>
#include <vector>

using namespace std;

int tri[501][501];
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int l = 0;
    for(auto line : triangle) {
        for(int i=0;i<line.size();i++) {
            tri[l][i] = line[i];
        }
        l++;
    }
    dp[0][0] = tri[0][0];
    for(int i=1;i<l;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0) dp[i][j] = dp[i-1][j] + tri[i][j];
            else if(j==i) dp[i][j] = dp[i-1][j-1] + tri[i][j];
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
            }
        }
    }
    for(int i=0;i<l;i++) {
        answer = max(dp[l - 1][i], answer);
    }
    return answer;
}