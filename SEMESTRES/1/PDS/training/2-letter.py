T = int(input())

def chr_to_idx(c: str) -> int:
    return ord(c)-97

for _ in range(T):
    N = int(input())

    chrs = [[0 for i in range(26)] for j in range(26)]

    for __ in range(N):
        f, s = input()

        chrs[chr_to_idx(f)][chr_to_idx(s)]

    ans = 0

    for i in range(25):
        for j in range(i, 26):
            # "ab" "aa" "bb" 
            # "ac" "aa" "bb"

            if i != j:
                ans += min(ans[i][j], ans[])