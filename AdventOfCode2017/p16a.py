import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

s = list("abcdefghijklmnop")
for line in sys.stdin.readline().split(","):
  print(line)
  if line[0] == "s":
    x = int(line[1:])
    s = s[-x:] + s[:-x]
  elif line[0] == "x":
    w = line[1:].split("/")
    a, b = map(int, w)
    s[a], s[b] = s[b], s[a]
  else:
    w = line[1:].split("/")
    a, b = w
    pa = s.index(a)
    pb = s.index(b)
    s[pa], s[pb] = s[pb],s[pa]
print("".join(s))