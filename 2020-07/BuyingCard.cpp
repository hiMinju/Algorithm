// Baekjoon no.11052
// First Write: 2019.05.07
// Last Write: 2020.07.21
// Minju Kim
// using 

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	vector<double> unit_arr;
	int temp = 0;
	int num = 0;
	double max = 0;
	int max_index = 0;
	int count = 0;
	int remainder = 0;
	int total = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> temp;
		arr.push_back(temp);
		unit_arr.push_back((double)arr[i] /(i + 1));
	}

	for (int i = 0; i < num; i++) {
		if (max < unit_arr[i]) {
			max = unit_arr[i];
			max_index = i;
		}
	}

	count = num / (max_index + 1);
	remainder = num - (count * (max_index + 1));

	if ((num % (max_index + 1) == 0)) {
		total = (int)arr[max_index] * count;
	}
	else {
		total = (int)arr[max_index] * count + arr[remainder - 1];
	}
	cout << total;

	return 0;
}