import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def check(cur, num, x, y, mem):
  offs = [(dx, dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1)]
  val = sum(mem[x+dx, y+dy] for dx, dy in offs)
  if val > num:
    print(cur, val)
    exit(0)
  mem[x, y] = val

num = int(sys.argv[1])
mem = defaultdict(int)
mem[0, 0] = 1
n = 1
x = 1
y = 0
cur = 2
check(cur, num, x, y, mem)
i = 0
while True:
  n += 2
  for xd, yd, k in [(0, 1, n-2), (-1, 0, n-1), (0, -1, n-1), (1, 0, n)]:
    for _ in range(0, k):
      x += xd
      y += yd
      cur += 1
      check(cur, num, x, y, mem)





