import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor


points = []
i = 0
for line in sys.stdin:
  values = list(map(int, re.findall(r"-?[0-9]+", line)))
  v = tuple(reversed([sum(map(abs, values[r:r+3])) for r in range(0, 7, 3)])) + (i,)
  points.append(v)
  i += 1
print(sorted(points))