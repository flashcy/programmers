#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    istringstream ss(s);
    string strBuf;
    vector<string> str;
    while(getline(ss, strBuf, ' ')) {
        str.push_back(strBuf);
    }
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == "Z") {
            answer -= stoi(str[i-1]);
        }
        else {
            answer += stoi(str[i]);
        }
    }
    
    return answer;
}