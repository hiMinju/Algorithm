//Baekjoon no.10828
// stack
// Minju Kim
// using stack

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void) {
	stack<int> s;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string temp;
		cin >> temp;
		
		if (temp == "pop") {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else
				cout << -1 << endl;
		}
		else if (temp == "size") {
			cout << s.size() << endl;
		}
		else if (temp == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (temp == "top") {
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else
				cout << -1 << endl;
		}
		else if (temp == "push") {
			int n;
			cin >> n;
			s.push(n);
		}
	}

	return 0;
}