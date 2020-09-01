// 2020-09-01
// Baekjoon no.1018
// Minju Kim
// Coloring the chess baord again using brute force

#include <iostream>
using namespace std;

const int INF = 987654321;
char mat[50][50];
int N, M;
char sample1[8] = { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' };
char sample2[8] = { 'W', 'B', 'W', 'B', 'W', 'B', 'W' , 'B' };

int compare(int x, int y) {
	int case1 = 0, case2 = 0;

	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			if (i % 2 == 0 && mat[j][i] != sample2[j-x]) {
				++case1;
			}
			else if (i % 2 != 0 && mat[j][i] != sample1[j - x]) {
				++case1;
			}

			if (i % 2 == 0 && mat[j][i] != sample1[j - x]) {
				++case2;
			}
			else if (i % 2 != 0 && mat[j][i] != sample2[j - x]) {
				++case2;
			}
		}
	}

	if (case1 < case2) {
		return case1;
	}
	else {
		return case2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	int result = INF;
	for (int i = 0; i+7 < N; i++) {
		for (int j = 0; j+7 < M; j++) {
			result = min(result, compare(i, j));
		}
	}

	cout << result << "\n";

	return 0;
}