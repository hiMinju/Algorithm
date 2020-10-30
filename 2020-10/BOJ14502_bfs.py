# 2020-10-30
# Baekjoon no.14502
# Minju Kim
# 연구소 using bfs and dfs

import copy
from collections import deque

dirs = [(-1,0), (1,0), (0,-1), (0,1)]
n, m = map(int, input().split())
lab = [] # n x m
temp = [[0]*m for _ in range(n)]
for r in range(n):
  lab.append(list(map(int, input().split())))

result = 0
def get_zero(temp)):
  score = 0
  for r in range(n):
    for c in range(m):
      if temp[r][c] == 0:
        score += 1
  return score

def bfs():
  global result
  temp = copy.deepcopy(lab)
  q = deque()
  for r in range(n):
    for c in range(m):
      if temp[r][c] == 2:
        q.append((r,c))  

  while q:
    r, c = q.popleft()
    for i in range(4):
      nc = c + dirs[i][0]
      nr = r + dirs[i][1]
      if 0 <= nr < n and 0 <= nc < m:
        if temp[nr][nc] == 0:
          temp[nr][nc] = 2
          q.append((nr,nc))
  result = max(result, get_zero(temp))

def dfs(count):
  global result
  if count == 3: # 바이러스 전파 영역 계산
    bfs()
    return
  for r in range(n):
    for c in range(m):
      if lab[r][c] == 0:
        lab[r][c] = 1
        dfs(count+1)
        lab[r][c] = 0
dfs(0)        
print(result)
