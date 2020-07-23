// Baekjoon no.11052
// First Write: 2019.05.07
// Last Write: 2020.07.23
// Minju Kim
// using dp
// bottom up

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int d[10001] = { 0 };
int arr[10001];
	
int main() {
	int num = 0;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + arr[j]);
		}
	}
	cout << d[num] << endl;

	return 0;
}