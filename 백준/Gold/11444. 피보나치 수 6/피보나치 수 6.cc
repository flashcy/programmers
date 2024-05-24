#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define MOD 1000000007
using namespace std;

vector<vector<long long>> v({ {1, 1}, {1,0} });

vector<vector<long long>> multiply(vector<vector<long long>>, vector<vector<long long>>);
vector<vector<long long>> matrix_pow(vector<vector<long long>>, long long);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	if (n > 1)
		v = matrix_pow(v, n - 1);
	cout << v[0][0] << "\n";

	return 0;
}

vector<vector<long long>> multiply(vector<vector<long long>> m1, vector<vector<long long>> m2) {
	vector<vector<long long>> result({ {0,0},{0,0} });
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
				result[i][j] %= MOD;
			}
		}
	}
	return result;
}

vector<vector<long long>> matrix_pow(vector<vector<long long>> M, long long exp) {
	if (exp == 1) {
		return M;
	}
	
	vector<vector<long long>> result = matrix_pow(M, exp / 2);

	result = multiply(result, result);

	if (exp % 2 == 1) {
		result = multiply(result, M);
	}

	return result;
}