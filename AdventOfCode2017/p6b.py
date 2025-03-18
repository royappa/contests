import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

banks = list(map(int, sys.stdin.readline().split()))
seen = dict()
sig = ",".join(map(str, banks))
num = 0
seen[sig] = num
print(sig)
n = len(banks)
while True:
  d = max(banks)
  p = banks.index(d)
  banks[p] = 0
  for q in range(p+1, p+d+1):
    banks[q%n] += 1
  sig = ",".join(map(str, banks))
  num = num + 1
  last = seen.get(sig)
  if last != None:
    print(num - last)
    exit(1)
  seen[sig] = num

  




