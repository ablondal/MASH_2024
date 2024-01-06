import sys
# with open(0) as f:
lines = sys.stdin.read().split('\n')
n, q = map(int, lines[0].split())

# We need a node per hockey card
# Two node per attribute (in and out)
# A node per query
# let_in = n
# speed_in = n+26
# height_in = speed_in+(71-15)

# let_out = height_in+(221-50)
# speed_out = let_out+26
# height_out = speed_out+(71-15)
# diff = let_out-let_in
# query_base = height_out+(221-50)
# num_nodes = query_base + q

adj = [[] for _ in range(n)]
# names = []
# Cards
cards = []
for i in range(n):
    na, sp, he = lines[i+1].split()
    cards.append((na, int(sp), int(he)))

def get_matches(selection):
    ty, a, b = selection.split()
    if ty == "Name":
        return [i for i in range(n) if a <= cards[i][0][0] and cards[i][0][0] <= b]
    elif ty == "Speed":
        return [i for i in range(n) if int(a) <= cards[i][1] and cards[i][1] <= int(b)]
    else:
        return [i for i in range(n) if int(a) <= cards[i][2] and cards[i][2] <= int(b)]

# Queries
for i in range(q):
    s1, s2 = lines[1+n+i].split('>')
    m1 = get_matches(s1)
    m2 = get_matches(s2)
    for a in m1:
        for b in m2:
            adj[a].append(b)

# Topo sort
indeg = [0 for _ in range(n)]
for i in range(n):
    for nxt in adj[i]:
        indeg[nxt] += 1
Q = []
Qi = 0
for i in range(n):
    if indeg[i] == 0:
        Q.append(i)

order = []
while len(Q) != 0:
    curr = Q.pop()
    if curr < n:
        order.append(curr)
    for nxt in adj[curr]:
        indeg[nxt] -= 1
        if indeg[nxt] == 0:
            Q.append(nxt)

if len(order) != n:
    print("your preferences are wrong")
else:
    print('\n'.join([cards[x][0] for x in order]))


