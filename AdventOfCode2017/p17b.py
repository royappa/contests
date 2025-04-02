import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

n = int(sys.argv[1])

LL = 1
p = -1
for i in range(50000000):
  p = (p + n) % LL
  p += 1
  LL += 1
  if p == 1:
    last = i + 1
print(last)

