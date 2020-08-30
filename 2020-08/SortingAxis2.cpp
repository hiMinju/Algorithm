// 2020-08-10
// Baekjoon no.11651
// Minju Kim
// Sorting Axis by y

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i].second >> vec[i].first;
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i].second << " " << vec[i].first << "\n";
	}

	return 0;
}