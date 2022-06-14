from copy import deepcopy

N, M, K = [int(i) for i in input().split(" ")]

password = input()

tests = []
for _ in range(M):
  tests.append(input())

P = int(input())

possibilities = []

def poss(caracters: list, k: int):
  if k == M:
    possibilities.append(caracters)
    return

  caracters = deepcopy(caracters)

  for c in tests[k]:
    poss(caracters + [ord(c)], k+1)

poss([], 0)

possibilities.sort()

i = 0
for c in password:
  if c == "#":
    print(chr(possibilities[P-1][i]), end="")
    i += 1
  else:
    print(c, end="")
