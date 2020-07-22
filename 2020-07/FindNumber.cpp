// Baekjoon no.1920
// 2020-07-22
// Find number in aay
// Minju Kim
// using binary search & quick sort

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int cnt;
int a[10000001];

bool binarySearch(int num, int L, int R) {
	while (L <= R) {
		int mid = (L + R) / 2;
		if (a[mid] == num) {
			printf("1\n");
			return true;
		}
		else if (a[mid] > num)
			R = mid - 1;
		else
			L = mid + 1;
	}
	printf("0\n");
	return false;
}

//void swap(int n1, int n2) {
//	int temp = a[n1];
//	a[n1] = a[n2];
//	a[n2] = temp;
//}

//// recursion version
//// divide & conquer
//void quickSort(int start, int end) {
//	int pivot = a[start];
//	int L = start + 1;
//	int R = end;
//
//	while(L <= R) {
//		// find bigger or equal with pivot in left side
//		while (a[L] < pivot) { L++; }
//		// find less or eqaul with pivot in right side
//		while (a[R] > pivot) { R++; }
//
//		if (L <= R) {
//			swap(L, R);
//		}
//	}
//
//	if (start < end) { // when more than one thing
//		swap(start, R); // swap pivot(start) and a[right]
//
//		quickSort(start, R - 1);
//		quickSort(R + 1, end);
//	}
//	// remain one
//	return;
//}

int main() {
	int n;
	
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	sort(a, a + n); // using library

	int m, num;
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &num);
		bool result = binarySearch(num, 0, n);
	}

	return 0;
}