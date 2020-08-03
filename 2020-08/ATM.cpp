// 2020-08-03
// Baekjoon no.11399
// Minju Kim
// The shortest time in waiting atm

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
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int prev = v[0];
	int sum = prev;
	for (int i = 1; i < n; i++) {
		prev += v[i];
		sum += prev;
	}
	cout << sum;

	return 0;
}