# 2020-10-20
# Baekjoon no.1012
# Minju Kim
# 유기농 배추
# using bfs

from collections import deque
dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
def bfs(start):
  queue = deque()
  queue.append(start)
  while queue:
    x, y = queue.popleft()
    mat[y][x] = 0
    if x < 0 or x >= len(mat[0]) or y < 0 or y >= len(mat):
      continue
    for dir in dirs:
      nx, ny = x + dir[0], y + dir[1]
      if 0 <= nx < len(mat[0]) and 0 <= ny < len(mat) and mat[ny][nx]:
        queue.append((nx, ny))
        mat[ny][nx] = 0

t = int(input())
for _ in range(t):
  # 테스트 케이스 만큼 반복
  result = 0
  m, n, k = map(int, input().split())
  mat = [[0]*m for _ in range(n)] # m이 x n이 y

  for _ in range(k):
    x, y = map(int, input().split())
    mat[y][x] = 1
  for y in range(n):
    for x in range(m):
      if mat[y][x] == 1:
        result += 1
        bfs((x, y))
  print(result)
