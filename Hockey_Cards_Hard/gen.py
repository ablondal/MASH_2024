from random import randrange

def genCard():
    name = ''.join([chr(ord('A')+randrange(26)) for _ in range(8)])
    speed = randrange(15,71)
    height = randrange(50, 221)
    return f"{name} {speed} {height}"

def genName():
    a, b = sorted([chr(ord('A')+randrange(26)) for _ in range(2)])
    b = a
    return f"Name {a} {b}"

def genSpeed():
    a, b = sorted([randrange(15,71), randrange(15, 71)])
    b = a
    return f"Speed {a} {b}"

def genHeight():
    a, b = sorted([randrange(50, 221), randrange(50, 221)])
    b = a
    return f"Height {a} {b}"

def genSel():
    i = randrange(3)
    return [genHeight, genName, genSpeed][i]()

def genRest():
    return f"{genSpeed()} > {genSpeed()}"

def toName(i, k):
    if k==0:
        return ''
    return ''.join([chr(ord('A')+(i%26))] + list(toName(i//26, k-1)))

# for i in range(1, 100):
#     print(toName(i, 3))
n = 100
q = 100
names = sorted([toName(i, 4) for i in range(n)])
# print(toName(100000, 3))
sp = (n // (71-15)) + 1
he = (n // (221-50)) + 1
ch = (n // 26) + 1
# print(sp, he, ch)

cards = [f"{names[i]} {15 + (i // sp)} {50 + (i // he)}" for i in range(n)]
qs = []
for qi in range(q):
    a,b,c,d = 0,0,0,0
    # while(c-b < 2*ch):
    #     a, b, c, d = sorted([randrange(n) for _ in range(4)])
    r1, r2 = randrange(3), randrange(3)
    if r1 == 0:
        r1 = f"Speed {15 + a//sp} {15 + b//sp}"
    elif r1 == 1:
        r1 = f"Height {50 + a//he} {50 + b//he}"
    else:
        r1 = f"Name {chr(ord('A')+(a//ch))} {chr(ord('A')+(b//ch))}"
    if r2 == 0:
        r2 = f"Speed {15 + c//sp} {15 + d//sp}"
    elif r2 == 1:
        r2 = f"Height {50 + c//he} {50 + d//he}"
    else:
        r2 = f"Name {chr(ord('A')+(c//ch))} {chr(ord('A')+(d//ch))}"
    
    qs.append(f"{r1} > {r2}")

print(n, q)
print('\n'.join(cards + qs))
# print('\n'.join([genCard() for _ in range(n)]))
# print('\n'.join([genRest() for _ in range(q)]))
