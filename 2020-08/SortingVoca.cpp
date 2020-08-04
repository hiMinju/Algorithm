// 2020-08-04
// Baekjoon no.1181
// Minju Kim
// Sorting string

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> s[51];
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		s[temp.size()].push_back(temp);
	}

	for (int i = 1; i <= 50; i++) {
		if (!s[i].empty()) {
			if (s[i].size() == 1)
				cout << s[i][0] << '\n';
			else {
				sort(s[i].begin(), s[i].end());
				s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end()); // erase the duplicated value
				for (int j = 0; j < s[i].size(); j++) {
					cout << s[i][j] << '\n';
				}
			}
		}
	}
	return 0;
}