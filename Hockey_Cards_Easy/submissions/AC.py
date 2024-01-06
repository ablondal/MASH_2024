lines = open(0).read().split('\n')
n, q = map(int, lines[0].split())

# We need a node per hockey card
# Two node per attribute (in and out)
# A node per query
let_in = n
speed_in = n+26
height_in = speed_in+(71-15)

let_out = height_in+(221-50)
speed_out = let_out+26
height_out = speed_out+(71-15)
diff = let_out-let_in
query_base = height_out+(221-50)
num_nodes = query_base + q

adj = [[] for _ in range(num_nodes)]
names = []
# Cards
for i in range(n):
    na, sp, he = lines[i+1].split()
    names.append(na)
    sp, he = int(sp)-15, int(he)-50
    
    st_let = ord(na[0])-ord('A')
    adj[let_in + st_let].append(i)
    adj[i].append(let_out + st_let)

    adj[speed_in + sp].append(i)
    adj[i].append(speed_out + sp)
    adj[height_in + he].append(i)
    adj[i].append(height_out + he)

def get_range(selection):
    ty, a, b = selection.split()
    if ty == "Name":
        return let_in + ord(a)-ord('A'), let_in + ord(b)-ord('A')
    elif ty == "Speed":
        return speed_in + int(a)-15, speed_in + int(b)-15
    else:
        return height_in + int(a)-50, height_in + int(b)-50

# Queries
for i in range(q):
    s1, s2 = lines[1+n+i].split('>')
    lo1, hi1 = get_range(s1)
    lo2, hi2 = get_range(s2)
    for x in range(lo1+diff, hi1+diff+1):
        adj[x].append(query_base+i)
    for x in range(lo2, hi2+1):
        adj[query_base+i].append(x)

# Topo sort
indeg = [0 for _ in range(num_nodes)]
for i in range(num_nodes):
    for nxt in adj[i]:
        indeg[nxt] += 1
Q = []
Qi = 0
for i in range(num_nodes):
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
    print('\n'.join([names[x] for x in order]))


