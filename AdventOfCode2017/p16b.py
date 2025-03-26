import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

t = "abcdefghijklmnop"
s = list(t)
prog = []
for line in sys.stdin.readline().split(","):
  line = line.strip()
  if line[0] == "s":
    prog.append(("s", int(line[1:]), 0))
  elif line[0] == "x":
    w = line[1:].split("/")
    a, b = map(int, w)
    prog.append(("x", a, b))
  else:
    w = line[1:].split("/")
    a, b = w
    prog.append(("p", a, b))

q = []
for i in range(65):
  for step in prog:
    if step[0] == "s":
      x = step[1]
      s = s[-x:] + s[:-x]
    elif step[0] == "x":
      a = step[1]
      b = step[2]
      s[a], s[b] = s[b], s[a]
    else:
      a = step[1]
      b = step[2]
      pa = s.index(a)
      pb = s.index(b)
      s[pa], s[pb] = s[pb], s[pa]
  t = "".join(s)
  q.append(t)
  if q[-60:-30] == q[-30:]:
    print(q[-30:])
    break
n = len(q)
print(n)
r = (1000000000 - n) - 1
print(q[-30:][r%30])
