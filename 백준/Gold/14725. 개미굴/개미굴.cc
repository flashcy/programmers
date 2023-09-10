#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#define INF 100000000
using namespace std;

struct Node {
	map<string, Node> child;
};

int N;

void insertNode(Node& p, vector<string> key, int idx) {
	if (idx == key.size()) return;
	if (p.child.find(key[idx]) != p.child.end()) {
		insertNode(p.child[key[idx]], key, idx + 1);
	}
	else {
		p.child.insert({ key[idx], Node() });
		insertNode(p.child[key[idx]], key, idx + 1);
	}
}

void PrintNode(Node& p, int depth) {
	for (auto node : p.child) {
		for (int i = 0; i < depth; i++) {
			cout << "--";
		}
		cout << node.first << '\n';
		PrintNode(node.second, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Node node;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		vector<string> input(n);
		for (int j = 0; j < n; j++) {
			cin >> input[j];
		}
		insertNode(node, input, 0);
	}
	PrintNode(node, 0);
	return 0;
}