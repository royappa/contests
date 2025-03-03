import sys
from collections import defaultdict
from collections import Counter

import hashlib

tot = 0
for line in sys.stdin:
  s = line.strip()
  n = len(s)
  inside = False
  start = -1
  num_in, num_out = 0, 0
  for i in range(0, n):
    if s[i] == '[' or s[i] == ']':
      inside = not inside
      start = i
      continue
    if (i-start < 4):
      continue
    t = s[i-3:i+1]
    tr = t[::-1]
    if t != tr or t[0] == t[1]:
      continue
    print(s, t, tr)
    if inside:
      num_in += 1
    else:
      num_out += 1   
  if (num_out and not num_in):
    print("valid", s)
    tot += 1
print(tot)
    
