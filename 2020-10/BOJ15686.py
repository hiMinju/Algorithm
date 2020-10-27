# 2020-10-27
# Minju Kim
# Baekjoon no.15686
# 치킨 배달 using 완전탐색

from itertools import combinations

n,m = map(int, input().split())
house, chicken = [], []
for i in range(n):
  city = list(map(int, input().split()))
  for j in range(n):
    if city[j] == 1:
      house.append((i,j))
    elif city[j] == 2:
      chicken.append((i,j))
possibles = list(combinations(chicken, m))

def get_min_sum(possible):
  answer = 0
  for hx, hy in house:
    dist=1e9
    for px, py in possible:
      dist = min(dist, abs(px-hx)+abs(py-hy))
    answer += dist
  return answer

result = 1e9
for possible in possibles:
  result = min(result, get_min_sum(possible))
print(result)