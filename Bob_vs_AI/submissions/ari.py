N, m = map(int, input().split())

def getprobs(p_list):
	n = len(p_list)
	DP = [[0 for _ in range(n+1)] for _ in range(n+1)]
	DP[0][0] = 1
	for i in range(n):
		for j in range(n):
			DP[i+1][j+1] += DP[i][j] * p_list[i]
			DP[i+1][j] += DP[i][j] * (1-p_list[i])
	return DP[n]

bob_probs = list(map(float, input().split()))
ai_probs = [list(map(float, input().split())) for _ in range(m)]
bobp2 = getprobs(bob_probs)
ai = [getprobs(a) for a in ai_probs]

ai_sums = [0 for _ in range(len(ai))]
tot_prob = 0
for i in range(N):
	bb = 1
	for j in range(len(ai)):
		ai_sums[j] += ai[j][i]
		bb *= ai_sums[j]
	tot_prob += bb * bobp2[i+1]
print(f"{tot_prob:.9f}")