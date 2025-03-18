import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

banks = list(map(int, sys.stdin.readline().split()))
seen = set()
seen.add(",".join(map(str, banks)))
print(",".join(map(str, banks)))
n = len(banks)
while True:
  p = banks.index(max(banks))
  d = banks[p]
  banks[p] = 0
  while d > 0:
    p = (p + 1) % n
    banks[p] = banks[p] + 1
    d = d - 1
  sig = ",".join(map(str, banks))
  if sig in seen:
    print(len(seen))
    exit(1)
  print(sig)
  seen.add(sig)

  




