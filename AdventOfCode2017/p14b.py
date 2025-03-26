import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

def knot_hash(s):
  v = [ord(i) for i in s] + [17, 31, 73, 47, 23]
  n = 256

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

  return "".join([format(reduce(xor, L[k:k+16]), "02x") for k in range(0, n, 16)])

def flood(A, sr, sc):
  if not(0 <= sr < 128 and 0 <= sc < 128) or A[sr][sc] != "1":
    return
  A[sr][sc] = "."
  for nr, nc in [(sr-1,sc), (sr,sc+1), (sr+1,sc), (sr,sc-1)]:
    flood(A, nr, nc)

# main  
seed = sys.argv[1]
A = [[] for _ in range(0, 128)]
for r in range(0, 128):
  s = format(int(knot_hash(seed + "-" + str(r)), 16), '0128b')
  A[r] = list(s)

sys.setrecursionlimit(20000) 
#print(sys.getrecursionlimit())  # Usually 1000
groups = 0
for r in range(0, 128):
  for c in range(0, 128):
    if A[r][c] == "1":
      flood(A, r, c)
      groups += 1
    #print(A[0])
print(groups)

