//Baekjoon no.2606
// virus
// Minju Kim
// using DFs

#include <iostream>

using namespace std;

int num;
bool arr[100] = {false};
bool mat[100][100] = { false };
int dfs(int c);

int main() {
	
	int connect_num;
	cin >> num;
	cin >> connect_num;

	for (int i = 0; i < connect_num; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		mat[n1 - 1][n2 - 1] = true;
		mat[n2 - 1][n1 - 1] = true;
	}
	arr[0] = true;
	cout << dfs(0) << endl;

	return 0;
}

int dfs(int c) {
	int count = 0;
	for (int i = 0; i < num; i++) {
		if (!arr[i] && mat[c][i]) { // 아직 i번째 방문 전 && 해당 컴퓨터 연결돼 있을 때
			++count;
			arr[i] = true;
			count += dfs(i);
		}
	}
	return count;
}