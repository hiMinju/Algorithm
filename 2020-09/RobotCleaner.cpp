// 2020-09-20 ~ 2020-09-21
// Minju Kim
// Baekjoon no.14503
// using simulation

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int map[50][50];
	int N, M, x, y, dir;

	cin >> N >> M;
	cin >> x >> y >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int result = 0;

	while (true) {
		if (map[x][y] == 0) { // 현재 부분 청소
			map[x][y] = 2;
			++result;
		}

		int check = 0;
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			int tempX = x + dx[dir];
			int tempY = y + dy[dir];

			if (map[tempX][tempY] == 0) { // a조건 만족
				check = 1;
				x = tempX;
				y = tempY;
				break;
			}
		}
		if (check == 1)
			continue;

		// 후진
		x += dx[(dir + 2) % 4];
		y += dy[(dir + 2) % 4];
		if (map[x][y] == 1) { // 종료 조건
			break;
		}
	}
	cout << result;

	return 0;
}