from math import lcm, floor, sqrt
from collections import defaultdict
n, k, l = map(int, input().split())
t = list(map(int, input().split()))

def get_facs(x):
    f = set()
    for a in range(1, floor(sqrt(x))+1):
        if x % a == 0:
            f.add(a)
            f.add(x//a)
    return list(f)

fac_dict = defaultdict(list)
for x in t:
    for f in get_facs(x):
        fac_dict[f].append(x // f)

m = 1<<64
for gcd, nums in fac_dict.items():
    if len(nums) < k:
        continue
    nums.sort()
    res = nums[k-1]
    m = min(m, res)

print(m*l)