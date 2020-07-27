// Baekjoon no.10989
// 2020.07.27
// Minju Kim
// Sorting Number size: 1 <= N <= 10000000
// n size <= 10000

#include <iostream>
#include <cstdio>

using namespace std;
int arr[10001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		++arr[temp];
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 1; j <= arr[i]; j++) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}