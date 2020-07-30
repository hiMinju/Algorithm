// 2020-07-28
// Baekjoon no.1406
// Minju Kim
// Editor

#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string txt;
	cin >> txt;
	list<char> editor;
	for (int i = 0; i < txt.length(); i++) {
		editor.push_back(txt.at(i));
	}

	list<char>::iterator iter = editor.end();

	int n, size, cursor = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (iter != editor.begin()) --iter;
		}
		else if (cmd == 'D') {
			if (iter != editor.end()) ++iter;
		}
		else if (cmd == 'B') { // 커서 왼쪽 문자 삭제
			if (iter != editor.begin()) iter = editor.erase(--iter);
		}
		else {
			char temp;
			cin >> temp;
			editor.insert(iter, temp);
		}
	}

	for (list<char>::iterator i = editor.begin(); i != editor.end(); i++) {
		cout << *i;
	}
	return 0;
}