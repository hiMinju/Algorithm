# 2020-10-28
# Minju Kim
# Baekjoon no.18352
# 특정거리의 도시 찾기 using bfs

from collections import deque

# 입력
n, m, k, x = map(int, input().split())
city = [[] for _ in range(n+1)]
for i in range(m):
  a, b = map(int, input().split())
  city[a].append(b)

# 초기화
distance = [-1]*(n+1) # 각 노드까지의 거리 초기화
distance[x] = 0 # 자기 자신까지 거리 0

# bfs
q = deque([x]) # 자기 자신부터 탐색 출발
while q:
  node = q.popleft()
  for next_node in city[node]:
    if distance[next_node] == -1:
      distance[next_node] = distance[node] + 1
      q.append(next_node)

check = False
for i in range(1, n+1):
  if distance[i] == k:
    print(i)
    check = True
if not check:
  print(-1)