# 2020-10-20
# Baekjoon no.1012
# Minju Kim
# 유기농 배추

import sys
sys.setrecursionlimit(50000)
direction = [[-1, 0], [1, 0], [0, -1], [0, 1]]

def checkDir(y,x):
  for dir in direction:
    temp_x = x + dir[0]
    temp_y = y + dir[1]
    if temp_x < 0 or temp_x >= len(mat[0]) or temp_y < 0 or temp_y >= len(mat):
      continue

    if mat[temp_y][temp_x] == 1:
      mat[temp_y][temp_x] = 2
      checkDir(temp_y, temp_x)
  
t = int(input())
for _ in range(t):
  # 테스트 케이스 만큼 반복
  result = 0
  m, n, k = map(int, input().split())
  mat = [[0]*m for _ in range(n)] # m이 x n이 y

  for _ in range(k):
    x, y = map(int, input().split())
    mat[y][x] = 1
  for i in range(n):
    for j in range(m):
      if mat[i][j] == 1:
        mat[i][j] = 2
        checkDir(i, j) # i: y j: x
        result += 1
  print(result)
