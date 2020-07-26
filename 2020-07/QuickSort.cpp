// 2020-07-26 
// Minju Kim
// quick sort

#include <iostream>
#include <cstdio>

using namespace std;

int arr[10000001];

void quick(int* data, int start, int end) {
	if (start >= end) {
		return; // size is one
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end - 1;
	int temp;

	while (i <= j) {
		while(i <= end && data[i] <= data[pivot]) {
			i++;
		}
		while (j > start && data[j] >= data[pivot]) {
			j--;
		}

		if (i > j) { // cross the pointer then swap j with pivot
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else { // swap i with j
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	// criteria is j
	quick(data, start, j - 1);
	quick(data, j + 1, end);
}

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	quick(arr, 0, num);
	for (int i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}