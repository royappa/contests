import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy


A = defaultdict(list)
n = 0
for line in sys.stdin:
  n += 1
  adj = list(map(int, re.findall(r"-?\d+", line)))
  v = adj[0]
  A[v] = adj

q = deque()
visited = set()

groups = 0
for head in range(0, n):
  if head in visited:
    continue
  groups += 1
  q.append(head)
  visited.add(head)
  while len(q) > 0:
    head = q.popleft()
    for nbr in A[head]:
      if nbr not in visited:
        visited.add(nbr)
        q.append(nbr)

print(groups)


