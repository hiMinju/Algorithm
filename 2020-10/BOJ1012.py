# 2020-10-20
# Baekjoon no.1012
# Minju Kim
# 유기농 배추

def dfs(y,x):
  if x < 0 or x >= len(mat[0]) or y < 0 or y >= len(mat):
    return False

  if mat[y][x] == 1:
    mat[y][x] = 2
    dfs(y - 1, x)
    dfs(y, x - 1)
    dfs(y + 1, x)
    dfs(y, x + 1)
    return True
  return False

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
      if dfs(i, j) == True:
        result += 1
  print(result)