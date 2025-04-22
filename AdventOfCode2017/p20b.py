import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor
import math

def f(t, p):
  px, py, pz, vx, vy, vz, ax, ay, az = p
  x = px + vx*t + ax*(t)*(t+1)//2
  y = py + vy*t + ay*(t)*(t+1)//2
  z = pz + vz*t + az*(t)*(t+1)//2
  return (x, y, z)

def solve2(p1, p2):
  px1, py1, pz1, vx1, vy1, vz1, ax1, ay1, az1 = p1
  px2, py2, pz2, vx2, vy2, vz2, ax2, ay2, az2 = p2
  a = ax1-ax2
  b = (2*(vx1-vx2)+(ax1-ax2))
  c = 2*(px1-px2)
  d = b*b - 4*a*c
  roots = set()
  if a == 0:
    if b != 0 and c % b == 0:
      t = -c // b
      if t >= 0:
        roots.add(t)
    return roots
  if d < 0:
    return roots
  sd = math.isqrt(d)
  if sd*sd != d:
    return roots
  if (-b + sd) % (2*a) == 0:
    t = (-b + sd)//(2*a)
    if t >= 0:
      roots.add(t)
  if (-b - sd) % (2*a) == 0:
    t = (-b - sd)//(2*a)
    if t >= 0:
      roots.add(t)
  return roots

points = []
i = 0
for line in sys.stdin:
  values = list(map(int, re.findall(r"-?[0-9]+", line)))
  points += [values]
  i += 1

roots = set()
for p1 in points:
  for p2 in points:
    if p1 == p2:
      continue
    roots |= solve2(p1, p2)

for t in sorted(roots):
  if t <= 0:
    continue
  d = defaultdict(list)
  for i, p in enumerate(points):
    d[f(t, p)].append(i)
  indices = []
  for k, v in d.items():
    if len(v) > 1:
      indices.extend(v)
  for j in sorted(indices, reverse=True):
    del points[j]
print("count", len(points))
