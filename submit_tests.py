# This is a janky program written by Ari Blondal for the sole purpose of making
# problem testing easier.
# Basically only supports time limits and whitespace-ignoring judging.
# Use as
# python3 submit_test.py <test folder> <command to run problem>
# It will judge all test cases in the test folder recursively (files ending in .in)
# and judge them against the outputs (corresponding files ending in .out)

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
			print('found')
			a = open(o.path, 'r').read().split()
			try:
				i = a.index('time_sec:')
				time_lim = int(a[i+1])
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
		elif outp.stdout.split() == open(c+'.out', 'r').read().split():
			print("\r"+c+": \033[1m\033[32mOK\033[0m       ", flush=True)
		else:
			print("\r"+c+": \033[1m\033[31mWA\033[0m       ", flush=True)
			fail = True

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