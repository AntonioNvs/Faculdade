d = {}

c = 1

for i in range(97, 123):
    for j in range(97, 123):
        if i != j:
            d[f"{chr(i)}{chr(j)}"] = c
            c += 1


T = int(input())

for _ in range(T):
    a, b = input()

    print(d[f"{a}{b}"])