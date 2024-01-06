import random, math

x = random.randrange(-1000000, 1000000) / 1000
y = random.randrange(-1000000, 1000000) / 1000

d_from_0 = math.sqrt(x*x + y*y)
r = random.randrange(math.ceil(d_from_0*1000), 2000001) / 1000

print(f"{x:.3f} {y:.3f} {r:.3f}")