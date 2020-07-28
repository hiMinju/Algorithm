// 2020-07-28
// BOJ no.10845
// Minju Kim
// Queue

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	queue<int> q;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (command == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else {
				printf("-1\n");
			}
		}
		else if (command == "size") {
			printf("%d\n", q.size());
		}
		else if (command == "empty") {
			if (q.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (command == "front") {
			if (!q.empty()) {
				printf("%d\n", q.front());
			}
			else {
				printf("-1\n");
			}
		}
		else if (command == "back") {
			if (!q.empty()) {
				printf("%d\n", q.back());
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}