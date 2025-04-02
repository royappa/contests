import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

prog = []
regs = defaultdict(int)
def val(r):
  try:
    int(r)
    return int(r)
  except ValueError:
    return regs[r]
last = 0
for line in sys.stdin:
  code = line.strip().split()
  if len(code) == 2:
    code += [None]
  prog += [code]
pc = 0
n = len(prog)
while 0 <= pc < n:
  op, x, y = prog[pc]
  if op == "snd":
    last = val(x)
  elif op == "set":
    regs[x] = val(y)
  elif op == "add":
    regs[x] += val(y)
  elif op == "mul":
    regs[x] *= val(y)
  elif op == "mod":
    regs[x] %= val(y)
  elif op == "rcv":
    if val(x):
      print(last)
      exit(1)
  elif op == "jgz":
    if val(x):
      pc += val(y)
      pc -= 1
  pc += 1


  



