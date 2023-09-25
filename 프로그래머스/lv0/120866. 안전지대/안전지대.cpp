#include <string>
#include <vector>

using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            if(board[i][j] == 1) {
                for(int k=0;k<8;k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny>=board.size() || ny<0 || nx >=board.size() || nx<0 ||
                      board[ny][nx] > 0) continue;
                    board[ny][nx] = 2;
                }
            }
        }
    }
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            if(board[i][j] == 0)
                answer++;
        }
    }
    return answer;
}