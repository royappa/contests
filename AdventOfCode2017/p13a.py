import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy


scan_range = [0] * 100
n = 0
for line in sys.stdin:
  d, r = map(int, re.findall(r"-?\d+", line))
  scan_range[d] = r
  n = max(n, d)

n += 1
scan_pos = [-1] * n
scan_dir = [0] * n
packet_depth = -1
severity = 0
for _ in range(0, n):
  for i in range(0, n):
    if scan_dir[i] == 0:
      scan_pos[i] += 1
      if scan_pos[i] == scan_range[i] - 1:
        scan_dir[i] = 1
    else:
      scan_pos[i] -= 1
      if scan_pos[i] == 0:
        scan_dir[i] = 0
  packet_depth += 1
  if scan_pos[packet_depth] == 0:
    severity += packet_depth * scan_range[packet_depth]
print(severity)

