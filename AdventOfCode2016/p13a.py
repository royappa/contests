import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

nbrs = [(-1,0), (0,1), (1,0), (0,-1)]
offset = 1362
start = (1,1)
end = (31,39)
dist = defaultdict(int)
dist[start] = 0
q = deque()
q.append(start)
while len(q) > 0:
  hx,hy = q.popleft()
  print((hx,hy))
  for (dx,dy) in nbrs:
    x,y = hx + dx, hy + dy
    val = x*x + 3*x + 2*x*y + y + y*y + offset
    b = val.bit_count()
    # print(x,y,val, f"{val:b}", b)
    if x < 0 or y < 0 or b%2 or (x,y) in dist: continue
    dist[(x,y)] = dist[(hx,hy)] + 1
    q.append((x,y))
    if (x,y) == end:
      print("Dist: ", dist[(x,y)])
      exit(1)
print("done")
 
    
