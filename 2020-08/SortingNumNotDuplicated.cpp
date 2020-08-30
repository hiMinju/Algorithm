// 2020-08-13
// Baekjoon no.10867
// Minju Kim
// Sorting nums without the duplicated num

#include <iostream>
#include <vector>
using namespace std;

bool arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vec(2001);
	int start = -1000;
	for (int i = 0; i < vec.size(); i++) {
		vec[i].first = start++;
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		vec[temp+1000].second = 1;
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].second == 1) {
			cout << vec[i].first << " ";
		}
	}

	return 0;
}