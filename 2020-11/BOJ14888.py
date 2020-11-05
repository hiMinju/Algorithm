# 2020-10-05
# Minju Kim
# Baekjoon no.14888
# 연산자 끼워넣기 using dfs

n = int(input())
data = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

_max = -1e9
_min = 1e9
def dfs(i, now):
  global _max, _min, add, sub, mul, div
  if i == n:
    _max = max(_max, now)
    _min = min(_min, now)
  else:
    if add > 0:
      add -= 1
      dfs(i+1, now+data[i])
      add += 1
    if sub > 0:
      sub -= 1
      dfs(i+1, now-data[i])
      sub += 1
    if mul > 0:
      mul -= 1
      dfs(i+1, now*data[i])
      mul += 1
    if div > 0:
      div -= 1
      dfs(i+1, int(now/data[i]))
      div += 1

dfs(1, data[0])
print(_max, _min, sep='\n')
