import sys
from math import sqrt

# Get test case #
#################
test_case_fifo = sys.argv[1]
with open(test_case_fifo, 'r') as f:
    x, y, r = map(float, f.read().split())

# Interactor functions #
########################
def fail(reason):
    print('-2') # If your program ever receives ERROR, terminate immediately!
    print(reason, file=sys.stderr)
    sys.exit(1)

def eval_query(xx,yy):
    d = r - sqrt((xx-x)*(xx-x) + (yy-y)*(yy-y))
    if d < 0:
        print(-1)
    else:
        print(f"{d:.9f}")

# Interactive part #
####################

tries_left = 1000
eval_query(0, 0)
while True:
    if tries_left <= 0:
        fail("Out of queries")
    tries_left -= 1
    try:
        q, xx, yy = input().split()
        xx, yy = float(xx), float(yy)
    except:
        fail("Couldn't parse query: Invalid formatting")
    if q == '!':
        d2 = sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy))
        if d2 < 0.001:
            print("Correct", file=sys.stderr)
            sys.exit(0)
        else:
            fail("Wrong Answer")
    elif q == '?':
        eval_query(xx, yy)
    else:
        fail("Invalid input. Not a query or a guess.")


