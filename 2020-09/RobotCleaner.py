# Baekjoon no.14503
# python version

n, m = map(int, input().split())
x, y, direction = map(int, input().split())

array = []
for _ in range(n):
  array.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

result = 0
while True:
  check = 0
  if array[x][y] == 0:
    array[x][y] = 2
    result += 1

  for _ in range(4):
    direction = (direction + 3)%4

    tempX = x + dx[direction]
    tempY = y + dy[direction]

    if array[tempX][tempY] == 0:
      check = 1
      x = tempX
      y = tempY
      break;

  if check == 1:
    continue
  
  x -= dx[direction]
  y -= dy[direction]

  if array[x][y] == 1:
    break

print(result)