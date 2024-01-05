from random import randrange
n = 200
k = 6
l = randrange(1,10001)

vs = [720*i for i in range(1,7)]

vs.extend(
    [randrange(1000,10001) for _ in range(n-len(vs))]
)

print(n, k, l)
print(' '.join(map(str, vs)))