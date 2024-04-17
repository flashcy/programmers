#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
deque<int> dq;
deque<int> ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    sort(dq.begin(), dq.end());
    ans.push_back(dq.front());
    dq.pop_front();
    bool b = false;
    while (dq.size()) {
        if (!b) {
            ans.push_back(dq.back());
            dq.pop_back();
            if (dq.size()) {
                ans.push_front(dq.back());
                dq.pop_back();
            }
            b = true;
        }
        else {
            ans.push_back(dq.front());
            dq.pop_front();
            if (dq.size()) {
                ans.push_front(dq.front());
                dq.pop_front();
            }
            b = false;
        }
    }
    long long answer = 0;
    for (int i = 1; i < N; i++) {
        answer += abs(ans[i] - ans[i - 1]);
    }
    sort(ans.begin(), ans.end());
    dq.push_back(ans.back());
    ans.pop_back();
    b = true;
    while (ans.size()) {
        if (!b) {
            dq.push_back(ans.back());
            ans.pop_back();
            if (ans.size()) {
                dq.push_front(ans.back());
                ans.pop_back();
            }
            b = true;
        }
        else {
            dq.push_back(ans.front());
            ans.pop_front();
            if (ans.size()) {
                dq.push_front(ans.front());
                ans.pop_front();
            }
            b = false;
        }
    }
    long long temp = 0;
    for (int i = 1; i < N; i++) {
        temp += abs(dq[i] - dq[i - 1]);
    }
    cout << max(temp, answer) << '\n';
    return 0;
}