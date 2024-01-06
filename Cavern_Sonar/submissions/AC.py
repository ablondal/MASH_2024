import sys
# Quad Binary Search
def query(x, y):
    print(f"? {x} {y}")
    ans = float(input())
    return ans

d_0 = float(input())
def bin_search(l, h, fn):
    lo = l
    hi = h
    while(abs(hi-lo) > 1e-6):
        md = (hi+lo)/2
        if fn(md):
            lo = md
        else:
            hi = md
    return hi

left = bin_search(
    -3001.0, 0,
    lambda x : query(x, 0) == -1
)
right = bin_search(
    0, 3001.0,
    lambda x : query(x, 0) != -1
)
x = (left+right)/2

bot = bin_search(
    -3001.0, 0,
    lambda y : query(x, y) == -1
)
top = bin_search(
    0, 3001.0,
    lambda y: query(x, y) != -1
)
y = (top+bot)/2

print(f"! {x} {y}")