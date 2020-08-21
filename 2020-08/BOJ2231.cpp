// 2020-08-18 - 2020-08-21
// Baekjoon no.2231
// Minju Kim
// discreted sum using brute force

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	bool flag = true;
	if (N / 10 == 0) {
		cout << 0;
		return 0;
	}

 	for (int i = 10; i <= N; i++) {
		flag = true;

		int sum = i;
		int num = i;
		do {
			sum += num % 10;
			num /= 10;
			if (sum > N) {
				flag = false;
				break;
			}
		} while (num > 0);

		if (flag && sum == N) {
			cout << i;
			flag = false;
			return 0;
		}
	}

	cout << 0;
	return 0;
}