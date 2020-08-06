// 2020-08-06
// Baekjoon no.1182
// Minju Kim
// Get sum of partial num
// using brute force

# include <iostream>
using namespace std;

int arr[21], choice[21];
int n, s, cnt = 0;

void bf(int num, int index, int max) {
	int sum = 0;
	if (index >= max) {
		for (int i = 0; i < index; i++) {
			sum += choice[i];
		}

		if (sum == s) {
			++cnt;
			return;
		}
		return;
	}

	if (num >= n) {
		return;
	}

	choice[index] = arr[num];
	bf(num + 1, index + 1, max);
	bf(num + 1, index, max);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		bf(0, 0, i+1);
	}
	cout << cnt << '\n';

	return 0;
}