# 2020-11-07
# Minju Kim
# Baekjoon no.1715
# 카드 정렬하기 using greedy & priority queue

import heapq

n = int(input())
h = []
for _ in range(n):
  heapq.heappush(h, int(input()))

result = 0
while len(h)!=1:
  first = heapq.heappop(h)
  second = heapq.heappop(h)
  result += first+second
  heapq.heappush(h, first+second)

print(result)