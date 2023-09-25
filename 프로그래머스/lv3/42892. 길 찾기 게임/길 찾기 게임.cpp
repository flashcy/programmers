#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
vector<int> inorder;
vector<int> postorder;
vector<int> preorder;

void dfs(int pSta, int pEnd, int inSta, int inEnd) {
    for (int i = inSta; i <= inEnd; i++) {
        if (inorder[i] == postorder[pEnd]) {
            int lLeng = i - inSta;
            int rLeng = inEnd - i;
            preorder.push_back(postorder[pEnd]);
            dfs(pSta, pSta + lLeng - 1, inSta, i - 1);
            dfs(pSta + lLeng, pSta + lLeng + rLeng - 1, i + 1, inEnd);
            break;
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    for(int i=0;i<nodeinfo.size();i++) {
        nodeinfo[i].push_back(i+1);
    }
    // inorder
    sort(nodeinfo.begin(), nodeinfo.end());
    for(auto node : nodeinfo) inorder.push_back(node[2]);
    // postorder
    stack<pair<int, int>> post;
    for(auto node : nodeinfo) {
        while(!post.empty() && post.top().first < node[1]) {
            postorder.push_back(post.top().second);
            post.pop();
        }
        post.push({node[1], node[2]});
    }
    while(!post.empty()) {
        postorder.push_back(post.top().second);
        post.pop();
    }
    dfs(0, nodeinfo.size() - 1, 0, nodeinfo.size() - 1);
    answer = {preorder, postorder};
    return answer;
}