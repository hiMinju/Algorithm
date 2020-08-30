// 2020-08-30
// Baekjoon no.7568
// Minju Kim
// Calculate the rank of weight and height using Brute-Force

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
		cin >> vec[i].first >> vec[i].second;
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (vec[i].first < vec[j].first) {
				if (vec[i].second < vec[j].second) {
					++rank;
				}
			}
		}
		cout << rank << "\n";
	}

	return 0;
}