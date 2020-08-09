// 2020-08-09
// Baekjoon no.11650
// Minju Kim
// Sorting Axis

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	vector<pair<int, int>> vec(num);

	for (int i = 0; i < num; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < num; i++) {
		cout << vec[i].first << " " << vec[i].second << '\n';
	}

	return 0;
}