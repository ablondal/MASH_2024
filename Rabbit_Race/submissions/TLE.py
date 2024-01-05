from math import lcm, gcd
n, k, l = map(int, input().split())
t = list(map(int, input().split()))

def get_min(n_left, ix, curr):
    curr_m = 1<<64
    for ixx in range(ix, n-n_left+1):
        c = curr + [t[ixx]]
        if n_left == 1:
            curr_m = min(
                curr_m,
                max(c) // gcd(*c)
            )
            # print(c, gcd(*c))
        else:
            curr_m = min(
                curr_m,
                get_min(n_left-1, ixx+1, c)
            )
    return curr_m

print(l * get_min(k, 0, []))