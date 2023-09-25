#include <string>
#include <vector>

using namespace std;

int fileMap[51][51];

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int l = 51, r = -1, u = 51, d = -1;
    for(int i = 0; i < wallpaper.size(); i++) {
        string str = wallpaper[i];
        for(int j = 0; j < str.length(); j++) {
            if(str[j] == '#') {
                fileMap[i][j] = 1;
                l = min(l, j);
                r = max(r, j + 1);
                u = min(u, i);
                d = max(d, i + 1);
            }
        }
    }
    answer = {u, l, d, r};
    return answer;
}