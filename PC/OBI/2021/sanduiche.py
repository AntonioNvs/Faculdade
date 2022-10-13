from copy import deepcopy

N, M = [int(i) for i in input().split(" ")]

pairs = [[0 for i in range(N+1)] for j in range(N+1)]

for _ in range(M):
    i, j = [int(i) for i in input().split(" ")]

    pairs[i][j] = 1
    pairs[j][i] = 1

count = 0

def work(arr: list) -> bool:
    for i in arr:
        for j in arr:
            if pairs[i][j] == 1:
                return False

    return True

def what_if(add: int, ingredients: list):
    global count

    if not work(ingredients):
        return

    if len(ingredients) > 0:
        count += 1
    
    if add == N+1:
        return

    print(ingredients, add)

    what_if(add+1, ingredients)

    arr = deepcopy(ingredients + [add])

    what_if(add+1, arr)

what_if(1, [])

print(count)
    