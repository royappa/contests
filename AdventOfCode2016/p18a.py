import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

line = sys.stdin.readline().strip()
print(len(line))
n = len(line)
tot = line.count(".")
print(line)
for i in range(0, 400000-1):
  line2 = list(line)
  for j in range(0, n):
    l = "." if j == 0 else line[j-1]
    m = line[j]
    r = "." if j == n-1 else line[j+1]
    s = l + m + r
    line2[j] = "^" if s in ["^^.", ".^^", "^..", "..^"]  else "."
  line = "".join(line2)
  # print(line)
  tot += line.count(".")
  
print(tot)