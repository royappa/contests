import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

v = list(map(int, sys.stdin.readline().split(",")))
print(v)
n = int(sys.argv[1])
print(n)

L = [i for i in range(0, n)]

skip = 0
p = 0
for len in v:
  q = (p + len - 1) % n
  q = (q + n) % n
  if len > 0:
    if p <= q:
      L[p:q+1] = reversed(L[p:q+1])
    else: # q < p
      M = L[q+1:p]
      R = list(reversed(L[p:] + L[:q+1]))
      qq = q + 1
      L = R[-qq:] + M + R[:-qq]
  p = (p + len + skip) % n
  skip = skip + 1
print(L[0] * L[1]) 




  




