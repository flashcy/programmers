#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int N;
vector<int> A;
vector<int> ans;
vector<int> repIdx;
vector<int> input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    input.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    A.push_back(input[0]);
    repIdx.resize(N, -2);
    repIdx[0] = 0;
    for (int i = 1; i < N; i++) {
        if (A.back() < input[i]) {
            A.push_back(input[i]);
            repIdx[i] = A.size() - 1;
        }
        // 같을 때에도 처리해줘야함.
        // 10 10 9 9 8 처럼 0 -1 0 -1 0 으로 처리되면 9 8로 결과가 출력됨.
        // 혹은 -2로 초기화 하면 0 => -1로 갈 일 없어서 9 8 출력될 일 없음.
        else if (A.back() > input[i]) {
            int l = 0, r = A.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (A[mid] >= input[i])
                    r = mid;
                else l = mid + 1;
            }
            A[r] = input[i];
            repIdx[i] = r;
        }
    }

    int idx = A.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (repIdx[i] == idx) {
            ans.push_back(input[i]);
            idx--;
        }
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}