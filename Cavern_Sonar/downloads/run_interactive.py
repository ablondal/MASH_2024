import subprocess, sys

###########################################
# Run this program like:
# python3 run_interactive.py "python3 interactor.py sample.in" "python3 your_program.py"

run_proc_1, run_proc_2 = sys.argv[1:3]

proc1 = subprocess.Popen(run_proc_1.split(),
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True
)

proc2 = subprocess.Popen(run_proc_2.split(),
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True
)

def end_interactive(reason):
    if proc1.poll() == None:
        proc1.kill()
    if proc2.poll() == None:
        proc2.kill()
    for line in proc1.stdout.readlines():
        print(f"judge >> {line}")
    print(f'ENDING INTERACTION because {reason}')
    sys.exit(0)

def comm(inp, type):
    proc = proc1 if type==1 else proc2
    if proc.poll() != None:
        end_interactive(f'Proc {type} ended.')
    try:
        if inp != None:
            proc.stdin.write(inp)
            proc.stdin.flush()
        out = proc.stdout.readline()
    except Exception as e:
        end_interactive(f"Exception: {e}")
    return out

print('STARTING INTERACTION')
out1 = None
out2 = None
try:
    out1 = proc1.stdout.readline()
except TimeoutError:
    end_interactive('Interactor wasn\'t communicating. Make sure the interactor command is the first argument')

print(f"judge >> {out1}")

while proc1.poll() == None:
    out2 = comm(out1, 2)
    print(f"prog >> {out2}")

    out1 = comm(out2, 1)
    print(f"judge >> {out1}")



if proc1.poll() == 1:
    print('WA')
elif proc1.poll() == 0:
    print('AC')
else:
    print("ERROR: unknown return code")
end_interactive('Interaction Done')
