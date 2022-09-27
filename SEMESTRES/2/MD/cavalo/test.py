import sys

sys.setrecursionlimit(int(10e8))

N = 60

grid = [[0 for i in range(N+1)] for j in range(N+1)]

movL = [-2, -1, 1, 2, 2, 1, -1, -2];
movC = [1, 2, 2, 1, -1, -2, -2, -1];

def limits(x, y):
  return x >= 1 and x <= N and y >= 1 and y <= N and grid[x][y] == 0

def get_degrees(x, y):
  degree = 0
  for i in range(8):
    if(limits(x + movL[i], y + movC[i])):
      degree += 1
  
  return degree

def get_the_bests_moviments(x, y):
  arr = []
  for i in range(8):
    nx = x + movL[i]
    ny = y + movC[i]
    
    if(limits(nx, ny)):
      arr.append((get_degrees(nx, ny), (nx, ny)))

  arr.sort()

  return arr

def backtracking(x, y, count):
  finish = count > N*N
  crr_idx = 0

  movs = get_the_bests_moviments(x, y)

  while not finish and crr_idx < len(movs):
    nx = movs[crr_idx][1][0]
    ny = movs[crr_idx][1][1]

    if(limits(nx, ny)):
      grid[nx][ny] = count

      finish = backtracking(nx, ny, count + 1)

      if(not finish):
        grid[nx][ny] = 0
      else:
        return finish

    crr_idx += 1

  return finish


if __name__ == "__main__":
  grid[1][1] = 1
  backtracking(1, 1, 2)

  for i in range(1, N+1):
    for j in range(1, N+1):
      if grid[i][j] >= 10:
        print(grid[i][j], end=" ")
      else:
        print(" " + str(grid[i][j]), end=" ")
    print()