# This is a janky program written by Ari Blondal for the sole purpose of making
# problem creation easier.
# Use as
# python3 create_outputs.py <test folder> <command to run problem>
# It will run the problem on all test cases in the test folder recursively
# (files ending in .in), and make outputs (corresponding files ending in .out)
import subprocess, traceback, os, sys

run_code = sys.argv[2:]
folder = sys.argv[1]
time_lim = 1

def recurscan(f_path):
	global time_lim
	tests = []
	for o in os.scandir(f_path):
		if o.is_file() and o.path.endswith('.in'):
			tests.append(o.path[:-3])
		elif o.is_file() and o.name == 'problem.yaml':
			a = open(o.path, 'r').read().split()
			try:
				i = a.index('time_sec:')
				time_lim = len(a[i+1])
				print('time limit:', time_lim)
			except:
				pass
		elif o.is_dir():
			tests.extend(recurscan(o.path))
	return tests

test_cases = recurscan(folder)

test_cases.sort()

fail = False

for c in test_cases:
	if fail:
		break
	print(c+": \033[1m\033[33mRunning\033[0m", end=' ', flush=True)
	try:
		outp = subprocess.run(
			run_code,
			stdin=open(c+'.in', 'r'),
			capture_output=True,
			text=True,
			timeout=time_lim)
		# print("\rDone!", flush=True)
		if outp.returncode != 0:
			print("\r"+c+": \033[1m\033[31mERR\033[0m       ", flush=True)
			fail = True
		else:
			with open(c+'.out', 'w') as f:
				f.write(outp.stdout)
			print("\r"+c+": \033[1m\033[32mOK\033[0m       ", flush=True)

		# print(outp.stdout)
	except subprocess.TimeoutExpired as err:
		print("\r"+c+": \033[1m\033[31mTLE\033[0m       ", flush=True)
		fail = True
	except subprocess.CalledProcessError as err:
		print("\r"+c+": \033[1m\033[31mERR\033[0m       ", flush=True)
		print(traceback.format_exc())
	except Exception as err:
		print(traceback.format_exc())

if not fail:
	print("\033[1m\033[32mAC\033[0m       ", flush=True)