#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int s : scoville)
        pq.push(s);
    
    int mixed = -1;
    while (pq.size() && pq.top() < K) {
        if (mixed == -1) {
            mixed = pq.top();
            pq.pop();
            continue;
        }
        mixed += pq.top() * 2;
        pq.pop();
        pq.push(mixed);
        mixed = -1;
        answer++;
    }
    
    if (mixed != -1) {
        while (mixed < K) {
            if (pq.empty()) {
                answer = -1;
                break;
            }
            if (mixed == -1) {
                mixed = pq.top();
                pq.pop();
                continue;
            }
            mixed += pq.top() * 2;
            pq.pop();
            pq.push(mixed);
            mixed = -1;
            answer++;
        }
    }
    
    return answer;
}