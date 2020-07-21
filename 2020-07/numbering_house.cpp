// Baekjoon no.2667
// 2020.07.21
// Minju Kim
// using bfs

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(queue<pair<int, int>> q);

bool check[25][25] = { false };
int mat[25][25];
int num, bfs_result = 0;

int main() {
	
	string temp;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> temp;
		for (int j = 0; j < num; j++) {
			mat[i][j] = stoi(temp.substr(j, 1));
		}
	}

	queue<pair<int, int>> queue;
	vector<int> result;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (!check[i][j] && mat[i][j] == 1) {
				pair<int, int> p = make_pair(i, j);
				queue.push(p);
				check[i][j] = true;

				bfs(queue);

				result.push_back(bfs_result);
				bfs_result = 0;
				queue.pop();
			}
		}
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());

	for (unsigned int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}

void bfs(queue<pair<int, int>> q) {
	pair<int, int> temp = q.front();
	int n1 = temp.first;
	int n2 = temp.second;
	++bfs_result;

	q.pop(); // 제일 상단 하나 빼기

	// up
	if (n1 > 0) {
		if (!check[n1 - 1][n2] && mat[n1 - 1][n2] == 1) {
			pair<int, int> p = make_pair(n1 - 1, n2);
			q.push(p);
			check[n1 - 1][n2] = true;
		}
	}
	// down
	if (n1 < num - 1) {
		if (!check[n1 + 1][n2] && mat[n1 + 1][n2] == 1) {
			pair<int, int> p = make_pair(n1 + 1, n2);
			q.push(p);
			check[n1 + 1][n2] = true;
		}
	}
	// left
	if (n2 > 0) {
		if (!check[n1][n2 - 1] && mat[n1][n2 - 1] == 1) {
			pair<int, int> p = make_pair(n1, n2 - 1);
			q.push(p);
			check[n1][n2 - 1] = true;
		}
	}
	// right
	if (n2 < num - 1) {
		if (!check[n1][n2 + 1] && mat[n1][n2 + 1] == 1) {
			pair<int, int> p = make_pair(n1, n2 + 1);
			q.push(p);
			check[n1][n2 + 1] = true;
		}
	}

	if (!q.empty())
		bfs(q);
}