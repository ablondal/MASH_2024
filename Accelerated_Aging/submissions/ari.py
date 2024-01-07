n = int(input())

DP = [0 for _ in range(max(n+1, 6))]

DP[1] = 1
DP[2] = 1
DP[3] = 2
DP[4] = 3
DP[5] = 4

for i in range(6, n+1):
	DP[i] = i-DP[i-1]
	if i % 2 == 0:
		DP[i] = max(DP[i], i-DP[i//2])
	if i % 3 == 0:
		DP[i] = max(DP[i], i-DP[i-2])
	if i % 5 == 0:
		DP[i] = max(DP[i], i-DP[i-3])

print(15+DP[n], 15+n-DP[n])