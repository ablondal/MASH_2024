n = int(input())
import math

x = 0.0
y = 0.0
dir = 0

for _ in range(n):
    a = input()
    if a == "stash":
        print(f"{x:.9f} {y:.9f}")
    else:
        c, r = a.split()
        if c == "spin":
            dir = (dir + int(r)) % 360
        elif c == "stride":
            ang = math.pi * dir / 180
            x += math.cos(ang) * float(r)
            y += math.sin(ang) * float(r)
