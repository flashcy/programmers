#include <iostream>
#include <vector>
using namespace std;

int input[202];
vector<int> A;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }
    
    for(int i = 0; i < N; i++) {
        if (A.size()) {
            if (A.back() < input[i]) {
                A.push_back(input[i]);
            } 
            else {
                int l = 0, r = A.size() - 1;
                while (l < r) {
                    int m = (l + r) / 2;
                    if (A[m] < input[i]) {
                        l = m + 1;
                    }
                    else {
                        r = m;
                    }
                }
                A[r] = input[i];
            }
        }
        else {
            A.push_back(input[i]);
            continue;
        }
    }
    
    cout << N - A.size();
}