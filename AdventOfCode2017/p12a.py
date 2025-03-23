import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy


A = dict()
n = 0
for line in sys.stdin:
  n = n + 1
  adj = list(map(int, re.findall(r"-?\d+", line)))
  v = adj[0]
  for e in adj[1:]:
    A[v,e] = A[e,v] = True

for i in range(0, n):
  A[i,i] = True

q = deque()
visited = set()
head = 0
q.append(head)
visited.add(head)

while len(q) > 0:
  head = q.popleft()
  for nbr in [x for x in range(0,n) if A.get((head,x), False)]:
    if nbr not in visited:
      visited.add(nbr)
      q.append(nbr)

print(len(visited))


