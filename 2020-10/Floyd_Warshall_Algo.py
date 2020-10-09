# Floyd-Warshall Algorithm
# 2020-10-09
# Book p.257
# Minju Kim

INF = int(1e9)

n = int(input()) # 노드의 개수 입력
m = int(input()) # 간선의 개수 입력
# 2차원 리스트(그래프 표현)를 만들고, 모든 값을 무한으로 초기화
graph = [[INF] * (n+1) for _ in range(n+1)]

# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
for a in range(1, n+1):
  for b in range(1, n+1):
    if a == b:
      graph[a][b] = 0

for _ in range(m):
  a, b, c = map(int, input().split())
  # a에서 b로 가는 비용은 c라고 설정
  graph[a][b] = c

# 점화식에 따라 플로이드 워셜 알고리즘을 수행
for k in range(1, n+1):
  for a in range(1, n+1):
    for b in range(1, n+1):
      graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

# 수행된 결과를 출력
for a in range(1, n+1):
  for b in range(1, n+1):
    # 도달할 수 없는 경우 INFINITY라고 출력
    if graph[a][b] == INF:
      print("INFINITY")
    else:
      print(graph[a][b], end=" ")
  print()