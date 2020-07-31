// 2020-07-31
// Baekjoon no.1463
// Minju Kim
// The number makes 1
// using bfs ==> runtime error

#include <iostream>
#include <queue>
using namespace std;

bool check[1000001];

int bfs(int x) {
	queue<pair<int, int>> q;
	int num = 0;
	check[x] = true;
	q.push(make_pair(x, 0));

	while (!q.empty()) {
		int front = q.front().first;
		int num = q.front().second;
		q.pop();

		if (front == 1) {
			return num;
		}

		if ((front % 3) == 0 && !check[front / 3]) {
			q.push(make_pair(front / 3, num + 1));
			check[front / 3] = true;
		}
		if ((front % 2) == 0 && !check[front / 2]) {
			q.push(make_pair(front / 2, num + 1));
			check[front / 2] = true;
		}
		if (!check[front - 1]) { // 1
			q.push(make_pair(front-1, num+1));
			check[front - 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;
	if (x == 1) {
		cout << 0;
		return 0;
	}

	cout << bfs(x);

	return 0;
}