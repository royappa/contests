import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from itertools import permutations

nodes = []
for line in sys.stdin:
  m = re.match(r"/dev/grid/node-x(\d+)-y(\d+)\s+(\d+)T\s+(\d+)T\s+(\d+)T\s+(\d+)%", line.strip())
  nodes.append(list(map(int, m.groups())))

num = 0
for a in nodes:
  for b in nodes:
    num = num + (a != b and a[3] > 0 and a[3] <= b[4])

print(num)

