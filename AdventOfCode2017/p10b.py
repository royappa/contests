import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

v = [ord(i) for i in sys.stdin.readline().strip()] + [17, 31, 73, 47, 23]
n = int(sys.argv[1])

L = [i for i in range(0, n)]

skip = 0
p = 0
for round in range(0, 64):
  for len in v:
    q = (p + len - 1) % n
    q = (q + n) % n
    if len > 0:
      if p <= q:
        L[p:q+1] = reversed(L[p:q+1])
      else: # q < p
        M = L[q+1:p]
        R = list(reversed(L[p:] + L[:q+1]))
        qn = q + 1
        L = R[-qn:] + M + R[:-qn]
    p = (p + len + skip) % n
    skip = skip + 1

T = "".join([format(reduce(xor, L[k:k+16]), "02x") for k in range(0, n, 16)])
print(T)




