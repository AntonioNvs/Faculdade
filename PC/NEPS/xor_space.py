S = input()
ans = ""

for c in S:
    ans += c.lower() if c.isupper() else c.upper()

print(ans)