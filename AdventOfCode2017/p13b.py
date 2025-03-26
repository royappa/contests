import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

scan_range = [[] for _ in range(0, 100)]
scan_len = [0] * 100
n = 0
for line in sys.stdin:
  d, r = map(int, re.findall(r"-?\d+", line))
  scan_range[d] = list(range(0,r)) + list(reversed(range(1,r-1)))
  scan_len[d] = len(scan_range[d])
  n = max(n, d)

n += 1
scan_pos = [0 if len(r) else -1 for r in scan_range]
delay = 0
while True:
  for depth in range(0, n):
    if scan_len[depth]:
      scan_pos[depth] = scan_range[depth][(depth + delay) % scan_len[depth]]
  if not any(pos == 0 for pos in scan_pos):
    print(delay)
    exit(0)
  delay += 1

