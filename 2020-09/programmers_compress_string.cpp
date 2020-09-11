// 2020-09-09
// Minju Kim
// 2020 KAKAO BLIND RECRUITMENT
// 문자열 압축

#include <string>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = s.size();
	int size = answer;

	if (size == 1) {
		return 1;
	}

	for (int i = 1; i <= size/2; i++) {
		string result = "";
		string temp = s.substr(0, i);
		int count = 1;
		for (int j = i; j <= size; j+=i) {
			if (temp == s.substr(j, i)) { // 조건 성립
				++count;
			}
			else {
				if (count == 1) {
					result += temp;
				}
				else {
					result += (to_string(count) + temp);
				}
				temp = s.substr(j, i);
				count = 1;
			}
		}
		result += s.substr((size / i) * i);
		answer = min(answer, (int)result.length());
	}
	return answer;
}

int main() {
	cout << solution("aabbaccc");

	return 0;
}