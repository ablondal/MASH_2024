import sys
from collections import deque
lines = sys.stdin.read().split('\n')

n, m = map(int, lines[0].split())
G = [['#']*(m+2)] + [['#'] + list(lines[i][:m]) + ['#'] for i in range(1,n+1)] + [['#']*(m+2)]
# print('\n'.join([''.join(g) for g in G]))

dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]

def reachable(x, y, dx, dy):
	x += dx
	y += dy
	r = []
	while G[y][x] != '#':
		r.append((x,y))
		x += dx
		y += dy
	return r

# dist = {(1,1,0):0, (1,1,1):0}
dist = [[[1000000, 1000000, 1000000, 1000000] for _ in range(m+2)] for _ in range(n+2)]
dist[1][1][0] = dist[1][1][1] = 0
vis = [[[False, False, False, False] for _ in range(m+2)] for _ in range(n+2)]
q = deque([(1,1,0), (1,1,1)])
# layer = 0
while len(q) != 0:
	# print(dist[q[0]], q)
	(x,y,d) = curr = q.popleft()
	if vis[y][x][d]:
		continue
	vis[y][x][d] = True
	dx, dy = dirs[d]
	cd = dist[y][x][d]

	# print(x, y, d, dist[(x,y,d)])

	for dd in [(d+1)%4, (d+3)%4]:
		if dist[y][x][dd] > cd+1:
			dist[y][x][dd] = cd+1
			q.append((x,y,dd))
	
	# print((x+dx,y+dy,d))
	if G[y+dy][x+dx] != '#' and dist[y+dy][x+dx][d] > cd:
		dist[y+dy][x+dx][d] = cd
		q.appendleft((x+dx, y+dy, d))
		# print(f"<-{(x+dx,y+dy,d)}")

mm = min(dist[y][x][d] for x,y,d in [(m,n,0),(m,n,1),(m,n,2),(m,n,3)])
# print(dist)
if mm == 1000000:
	print(-1)
else:
	print(mm)