#include <string>
#include <vector>

using namespace std;

int left = 10; // *
int right = 12; // #

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int number : numbers) {
        int k = number;
        if(k == 0) k = 11;
        if(k % 3 == 1) {
            left = k;
            answer += 'L';
            continue;
        }
        if(k % 3 == 0) {
            right = k;
            answer += 'R';
            continue;
        }
        int ly = (left - 1) / 3;
        int lx = (left - 1) % 3;
        int ry = (right - 1) / 3;
        int rx = (right - 1) % 3;
        int cy = (k - 1) / 3;
        int cx = (k - 1) % 3;
        
        // distance.
        int ld = abs(ly - cy) + abs(lx - cx);
        int rd = abs(ry - cy) + abs(rx - cx);
        
        // 왼손이 더 가까움
        if(ld < rd) {
            left = k;
            answer += 'L';
            continue;
        }
        // 오른손이 더 가까움
        if(ld > rd) {
            right = k;
            answer += 'R';
            continue;
        }
        
        if(hand == "left") {
            left = k;
            answer += 'L';
        }
        else {
            right = k;
            answer += 'R';
        }
    }
    return answer;
}