#include <string>
#include <vector>

using namespace std;

const int INF = 100000000;
int fw[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            fw[i][j] = INF;
            if(i == j)
                fw[i][j] = 0;
        }
    }
    
    for(auto fare : fares) {
        fw[fare[0]][fare[1]] = fare[2];
        fw[fare[1]][fare[0]] = fare[2];
    }
    
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
        answer = min(answer, fw[i][s] + fw[i][a] + fw[i][b]);
    }
    
    return answer;
}