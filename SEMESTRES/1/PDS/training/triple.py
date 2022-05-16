t = int(input())

for i in range(t):
    n = int(input())

    nums = [int(k) for k in input().split()]

    appeared = {}
    dont_have = -1

    for nu in nums:
        try:
            appeared[nu] += 1

            if appeared[nu] == 3:
                dont_have = nu
                break
        except KeyError:
            appeared[nu] = 1
    
    print(dont_have)

