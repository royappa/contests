import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from itertools import permutations

def grid_dist(grid, a, b):

  q = deque()
  head = (a[0], a[1])
  target = (b[0], b[1])
  q.append(head)
  dist = dict()
  dist[head] = 0
  while len(q) > 0:
    head = q.popleft()
    r,c = head[0], head[1]
    for dr,dc in [(-1,0),(0,1),(1,0),(0,-1)]:
      nr = r + dr
      nc = c + dc
      nbr = (nr,nc)
      if grid[nr][nc] != '#' and not (nr,nc) in dist:
        dist[nbr] = dist[head] + 1
        if nbr == target:
          return dist[nbr]
        q.append(nbr)
  print(a, "to ", b, "not found!")

# main
grid = []
positions = []
for r, line in enumerate(sys.stdin, 0):
  line = line.strip()
  grid.append(line)
  positions += [(r, c, line[c]) for c in range(0, len(line)) if line[c].isdigit()]

positions.sort(key = lambda x: x[2])
all_dist = dict()
for p in positions:
  for q in positions:
    if p == q: continue
    all_dist[(p[2], q[2])] = grid_dist(grid, p, q)

best = float('inf')
for seq in permutations(positions[1:]):
  prev = positions[0]
  cost = 0
  for cur in seq:
    cost += all_dist[(prev[2], cur[2])]
    prev = cur
  cost += all_dist[(cur[2], '0')]
  best = min(best, cost)

print(best)
  



 
    
