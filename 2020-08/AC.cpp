// 2020-08-05
// Baekjoon no.5430
// Minju Kim
// Use two functions in integer arr

#include <iostream>
#include <deque>	
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		int n, R = 0;
		cin >> n;
		deque<string> arr;
		string nums;
		cin >> nums;
		nums = nums.substr(1, nums.size()-2);
		istringstream ss(nums);
		string stringBuffer;
		// 문자열 입력
		while (getline(ss, stringBuffer, ','))
		{
			arr.push_back(stringBuffer);
		}

		bool error = false;
		for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
			//*iter
			if (*iter == 'R') { //reverse
				++R;
			}
			else { //delete
				if (arr.empty()) {
					error = true;
					break;
				}
				if (R % 2 == 0) {
					arr.pop_front();
				}
				else {
					arr.pop_back();
				}
			}
		}

		if (error) {
			cout << "error" << '\n';
		}
		else {
			cout << "[";
			if (R % 2 == 0) {
				while (!arr.empty()) {
					cout << arr.front();
					arr.pop_front();
					if (!arr.empty()) {
						cout << ",";
					}
				}
			}
			else {
				while (!arr.empty()) {
					cout << arr.back();
					arr.pop_back();
					if (!arr.empty()) {
						cout << ",";
					}
				}
			}
			cout << "]" << '\n';
		}
	}
	return 0;
}