import random

def mdc(a, b):
    if (b == 0):
        return a
    else:
        return mdc(b, a % b)
    
N = int(input())

quocient = 0

init = 2
end = 999999999999999

for k in range(N):
    mdc_equals_one = 0
    for i in range(10):
        a = random.randint(init, end)
        b = random.randint(init, end)

        calc = mdc(max(a, b), min(a, b))
        if calc == 1: mdc_equals_one += 1
    

    quocient += mdc_equals_one / N

print(quocient / 10)