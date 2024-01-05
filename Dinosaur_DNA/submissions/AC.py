wds = open(0).read().split()[1:]
wds.sort(key=len)
# print(wds)
ans = []
sm_wds = []

def match(wa, wb, i):
    if i + len(wa) > len(wb):
        return False
    for j in range(len(wa)):
        if wa[j] != wb[i+j]:
            return False
    return True

for w in wds:
    poss = [(False, -1, '') for _ in range(len(w)+1)]
    poss[0] = (True, -1, '')
    for i in range(len(w)):
        if poss[i][0]:
            for w2 in sm_wds:
                # if match(w2, w, i):
                if w2 == w[i:i+len(w2)]:
                    poss[i+len(w2)] = (True, i, w2)
    if poss[len(w)][0]:
        ans = []
        curr = len(w)
        while curr != 0:
            ans.append(poss[curr][2])
            curr = poss[curr][1]
        ans = ans[::-1]
        break
    sm_wds.append(w)

if ans == []:
    print("No")
else:
    print("Yes")
    print(f"{' + '.join(ans)} = {''.join(ans)}")