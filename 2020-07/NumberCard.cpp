// 2020-07-24
// Baekjoon no.10815
// Minju Kim
// number card

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int cards[500001];

bool BinarySearch(int l, int r, int target) {
	int mid = (l + r) / 2;

	while (l <= r) {
		if (cards[mid] == target) {
			return true;
		}
		else if (target < cards[mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
		mid = (l + r) / 2;
	}
	return false;
}

int main() {	
	int n, m, temp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}
	sort(cards, cards + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		
		if (BinarySearch(0,n-1,temp))
			printf("1 ");
		else
			printf("0 ");
	}
	return 0;
}