count = input()

nums = count.split("+")

nums.sort()

for n in nums[:len(nums)-1]:
    print(f"{n}+", end="")

print(nums[-1])