import math

def quantity_of_divisers(n):
    ans = 0

    for i in range(2, math.floor(n / 2) + 2):
        if n % i == 0:
            ans += 1

    return ans

r = int(input())

maxi_until_now = -1

for i in range(4, r+1):
    qtd = quantity_of_divisers(i)

    if qtd > maxi_until_now:
        print(i)
        maxi_until_now = qtd