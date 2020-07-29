// 2020-07-28
// Baekjoon no.1406
// Minju Kim
// Editor

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string txt;
	cin >> txt;

	int n, size, cursor = 0;
	cin >> n;
	size = txt.length();
	cursor = txt.length();

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "L") {
			if (cursor == 0)
				continue;
			else {
				--cursor;
			}
		}
		else if (cmd == "D") {
			if (cursor == size)
				continue;
			else {
				++cursor;
			}
		}
		else if (cmd == "B") {
			if (cursor == 0)
				continue;
			else if (cursor == 1) {
				txt = txt.substr(1);
			}
			else if(cursor == size) {
				txt = txt.substr(0, cursor - 1);
			}
			else {
				string temp;
				temp = txt.substr(0, cursor - 1);
				temp += txt.substr(cursor);
				txt = temp;
			}
			--cursor;
		}
		else if (cmd == "P") {
			string s, temp;
			cin >> s;

			if (cursor == 0) {
				temp = s;
				temp += txt;
				txt = temp;
			}
			else if (cursor == size) {
				txt += s;
			}
			else {
				temp = txt.substr(0, cursor);
				temp += s;
				temp += txt.substr(cursor);
				txt = temp;
			}
			++cursor;
		}
		size = txt.length();
	}

	cout << txt;
	return 0;
}