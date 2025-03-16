import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from itertools import permutations

nodes = [[0] * 33 for _ in range(30)]
for line in sys.stdin:
  m = re.match(r"/dev/grid/node-x(\d+)-y(\d+)\s+(\d+)T\s+(\d+)T\s+(\d+)T\s+(\d+)%", line.strip())
  x, y, tot, used, avail, per = map(int, m.groups())
  #print(x, y, line)
  nodes[y][x] = used

for y in range(0, 30):
  for x in range(0, 33):
    print("G" if (x,y) == (32,0) else "_" if nodes[y][x] == 0 else "#" if nodes[y][x] >100 else ".", end="")
  print()
print(12+29+28+31*5+1)

