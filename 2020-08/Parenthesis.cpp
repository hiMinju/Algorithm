// 2020-08-14
// Baekjoon no.9012
// Minju Kim
// Valid the parenthesis using stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		stack<char> s;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str.at(j) == '(') {
				s.push('(');
			}
			else { // )
				if (s.empty()) {
					s.push(')');
				}
				if (s.top() == '(') {
					s.pop();
				}
				else if (s.top() == ')') {
					break;
				}
			}
		}
		if (s.empty()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}