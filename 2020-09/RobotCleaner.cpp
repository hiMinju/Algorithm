// 2020-09-20
// Minju Kim
// Baekjoon no.14503
// using simulation

#include <iostream>
using namespace std;

int room[50][50];
int num = 0, dir = 0, r, c, result = 0;
bool flag = false;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x, y;
	cin >> N >> M;
	cin >> x >> y >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			room[i][j] = temp;
			if (temp == 0) ++num;
		}
	}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0 ,-1 };

	while (true) {
		if (room[x][y] == 0) { // 1번 현재 위치 청소
			room[x][y] = 2;
			++result;
		}

		int check = 0;
		for (int i = 0; i < 4; i++) { // 네 방향 모두 탐색
			dir = (dir + 3) % 4;

			int tempX = x + dx[dir];
			int tempY = y + dy[dir];
			if (room[tempX][tempY] == 0) { // 청소할 곳을 찾으면
				x = tempX;
				y = tempY;
				check = 1;
				break;
			}
		}
		if (check == 1)
			continue;

		// 후진
		int temp_dir = dir - 2;
		x += dx[(dir + 2) % 4];
		y += dy[(dir + 2) % 4];

		if (room[x][y] == 1)
			break;
	}

	cout << result;
	return 0;
}