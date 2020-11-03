# 2020-11-04
# Minju Kim
# BOJ 18405
# 경쟁적 전염 using bfs

from collections import deque

virus = []
n, k = map(int, input().split())

dirs = [(-1,0),(1,0),(0,-1),(0,1)]
mat = []
for i in range(n):
  mat.append(list(map(int, input().split())))
  for j in range(n):
    if mat[i][j] != 0:
      virus.append((mat[i][j], 0, i, j))
_s, _x, _y = map(int, input().split())
virus.sort()
q = deque(virus)
while q:
  k, s, x, y = q.popleft()
  if s == _s:
    break
  for d in dirs:
    nx = x + d[0]
    ny = y + d[1]
    if nx < 0 or nx >= n or ny < 0 or ny >= n:
      continue
    if mat[nx][ny] == 0:
      mat[nx][ny] = k
      q.append((k, s+1, nx, ny))

print(mat[_x-1][_y-1])