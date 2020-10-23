# 2020-10-23
# Baekjoon no.3190 snake
# Minju Kim
# Simulation Problem

n = int(input())
arr = [[0]*(n+1) for _ in range(n+1)]
apple = []
k = int(input())
for i in range(k):
  a, b = map(int, input().split())
  arr[a][b] = 1

dirs = [[0,1],[1,0],[0,-1],[-1,0]]

l = int(input())
for _ in range(l):
  x, c = input().split()
  apple.append((int(x), c))

x, y = 1, 1
arr[x][y] = 2
d = 0 # 방향
snake = [(1,1)]
t = 0
index = 0 # 몇 번째 회전

while True:
  x = x + dirs[(4+d)%4][0]
  y = y + dirs[(4+d)%4][1]

  if 1 <= x <= n and 1 <= y <= n and arr[x][y] != 2:
    # 벽을 만나거나 뱀의 몸통과 만나지 않았을 때
    if arr[x][y] == 0:
      # 사과가 없을 때
      px, py = snake.pop(0)
      arr[px][py] = 0
    arr[x][y] = 2 # 뱀 머리 영역 추가
    snake.append((x,y))
    t += 1

  else:
    t += 1
    break
  # index 범위 체크
  if index < l and t == apple[index][0]:
    if apple[index][1] == 'L':
      d -= 1
    else:
      d += 1
    index += 1
print(t)  
