// 2020-08-18
// Baekjoon no.2798
// Minju Kim
// Black jack using brute force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	int max = 0;
	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N-1; j++) {
			for (int k = j+1; k < N; k++) {
				if (vec[i] + vec[j] + vec[k]<=M &&vec[i] + vec[j] + vec[k] > max)
					max = vec[i] + vec[j] + vec[k];
			}			
		}
	}
	
	cout << max;
	return 0;
}