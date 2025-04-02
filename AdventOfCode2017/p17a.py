import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

n = int(sys.argv[1])

L = [0]
p = -1
print(L)
for i in range(2017):
  p = (p + n) % len(L)
  p += 1
  L = L[:p] + [i+1] + L[p:]
  val = L[p+1] if p+1 < len(L) else None
print(val)

