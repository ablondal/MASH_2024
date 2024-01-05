import sys

# Checker functions #
#####################
def fail(reason="Wrong Answer"):
    print(reason, file=sys.stderr)
    exit(1)

# Get test case, reading input the same way as the user #
#########################################################
wds = open(0).read().split()[1:]
words = set(wds)

# Get user answer #
###################
with open('user.out', 'r') as f:
    user_out = f.read()

# Get hint / actual answer #
############################
with open('ans.out', 'r') as f:
    ans = f.read()
    possible = ans.split()[0]

# Evaluate user answer #
########################

# We're being very very kind here with parsing
u_words = user_out.replace('+',' ').replace('=',' ').split()

# print(u_words)

if possible == 'No':
    if u_words != ['No']:
        fail()
elif len(u_words) < 4:
    fail()
else:
    if u_words[0] != 'Yes':
        fail()
    if any([w not in words for w in u_words[1:]]):
        fail()
    if ''.join(u_words[1:-1]) != u_words[-1]:
        fail()

print("AC", sys.stderr)
exit(0)