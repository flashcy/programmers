#include <iostream>	
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	getline(cin, str);
	string tmp;
	getline(cin, tmp);

	int answer = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str.size() - i < tmp.size()) break;
		bool chk = true;
		for (int j = 0; j < tmp.size(); j++) {
			if (str[i + j] != tmp[j]) {
				chk = false;
				break;
			}
		}
		if (chk) {
			i += tmp.size() - 1;
			answer++;
		}
	}
	cout << answer << '\n';
}