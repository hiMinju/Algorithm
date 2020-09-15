// 2020-09-15
// Minju kim
// sticker
// using dynamic programming

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100001;

int buf[2][MAX] = { 0, };
int dp[2][MAX] = { 0, };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		memset(buf, 0, sizeof(buf));
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= n; j++) {
			cin >> buf[0][j];
		}
		for (int j = 1; j <= n; j++) {
			cin >> buf[1][j];
		}
		
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = buf[0][1];
		dp[1][1] = buf[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1],dp[1][j - 2]) + buf[0][j];
			dp[1][j] = max(dp[0][j - 1],dp[0][j - 2]) + buf[1][j];
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}

	return 0;
}