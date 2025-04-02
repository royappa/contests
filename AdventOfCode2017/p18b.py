import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

prog = []
for line in sys.stdin:
  code = line.strip().split()
  if len(code) == 2:
    code += [None]
  prog += [code]
pc = 0
n = len(prog)

regs = [defaultdict(int), defaultdict(int)]
def val(id, r):
  try:
    int(r)
    return int(r)
  except ValueError:
    return regs[id][r]
last = 0
pcs = [0, 0]
queues = [deque(), deque()]
numSentBy1 = 0
ran = [True, True]
regs[0]["p"] = 0
regs[1]["p"] = 1
wait = [False, False]
while True:
  for id in range(2):
    if (not wait[id]) and (0 <= pcs[id] < n):
      op, x, y = prog[pcs[id]]
      print("run", id, pcs[id], op, len(queues[0]), len(queues[1]), wait[0], wait[1])
      if op == "snd":
        queues[id].append(val(id, x))
        numSentBy1 += id == 1
        wait[1-id] = False
      elif op == "set":
        regs[id][x] = val(id, y)
      elif op == "add":
        regs[id][x] += val(id, y)
      elif op == "mul":
        regs[id][x] *= val(id, y)
      elif op == "mod":
        regs[id][x] %= val(id, y)
      elif op == "rcv":
        if len(queues[1-id]):
          regs[id][x] = queues[1-id].popleft()
        else:
          wait[id] = True
          pcs[id] -= 1
      elif op == "jgz":
        if val(id, x) > 0:
          pcs[id] += val(id, y)
          pcs[id] -= 1
      pcs[id] += 1
  if wait[0] and wait[1]:
    break
print(numSentBy1)


  



