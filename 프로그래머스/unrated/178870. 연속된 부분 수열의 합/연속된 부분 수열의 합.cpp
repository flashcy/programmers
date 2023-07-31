#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> result;
    int sum = 0;
    int start = 0;
    for(int i=0; i<sequence.size(); i++) {
        sum += sequence[i];
        while(sum >= k) {
            if(sum == k) {
                result.push_back({start, i});
            }
            sum -= sequence[start];
            start++;
        }
    }
    int leng = result[0].second - result[0].first + 1;
    answer.push_back(result[0].first);
    answer.push_back(result[0].second);
    for(int i=1; i<result.size(); i++) {
        if(leng > result[i].second - result[i].first + 1) {
            leng = result[i].second - result[i].first + 1;
            answer[0] = result[i].first;
            answer[1] = result[i].second;
        }
    }
    return answer;
}