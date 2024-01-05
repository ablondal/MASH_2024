# n = 41
# sz = 200
# beg = sz - (n//2)
from random import choice
import sys

def mkword(x):
    return ''.join([choice(['A', 'C', 'G', 'T']) for _ in range(x)])

# words = [mkword(i) for i in range(beg, beg+n)]
# words.append('A'*1800)

# w = 'A'*40 + 'C'*40 + 'G'*40 + 'T'*40
# w = w*300 + 'A'
# cksz = 5
words = []
# for cksz in range(3, 6):
#     newword = list(set([mkword(cksz) for _ in range(10*cksz)]))
#     words.extend(newword)

# n_proof = 1400
# bigsz = (50000 - sum(map(len, words))) // n_proof

# words.extend([mkword(bigsz) for _ in range(n_proof)])

# ws.append(w)
# print(2)
words = ['A'*i for i in range(120, 240)]
words.append('A'*(49999 - sum(map(len,words)))+'C')
# words = ['A'*i + mkword(4) for i in range(900, 1000)]
# words.extend(['A'*i for i in range(100, 200)])
# words.append('A'*1000 + 'T')

print(len(words))
print('\n'.join(words))
print(sum(map(len, words)), file=sys.stderr)