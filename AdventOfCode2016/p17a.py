import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def num(r, c):
  return r*4 + c

def node_str(n):
  return None if n is None else str(n // 4) + "," + str(n%4)

def is_open(door, passwd):
  m = [0,3,1,2][door]
  hash = hashlib.md5(passwd.encode()).hexdigest()
  print(hash[:4])
  return hash[m] >= "b" and hash[m] <= "f" 

nbrs = defaultdict(lambda: [None] * 4)
U,R,D,L = 0,1,2,3
urdl = "URDL"

for r in range(0,4):
  for c in range(0,4):
    node = r*4 + c
    nbrs[node][U] = (num(r-1, c), True) if r > 0 else (None, False) 
    nbrs[node][R] = (num(r, c+1), True) if c < 3 else (None, False)
    nbrs[node][D] = (num(r+1, c), True) if r < 3 else (None, False)
    nbrs[node][L] = (num(r, c-1), True) if c > 0 else (None, False)
   
# THIS IS ALL WRONG, WORKED BY COINCIDENCE
# ROOM 3,3 is the bottom. See part b.
nbrs[num(3,3)][R] = (num(3,4), False)
nbrs[num(3,3)][D] = (num(4,3), False)

nbrs[num(3,4)][U] = (None, False)
nbrs[num(3,4)][R] = (None, False)
nbrs[num(3,4)][D] = (num(4,4), False)
nbrs[num(3,4)][L] = (num(3,3), False)

nbrs[num(4,3)][U] = (num(3,3), False)
nbrs[num(4,3)][R] = (num(4,4), False)
nbrs[num(4,3)][D] = (None, False)
nbrs[num(4,3)][L] = (None, False)

nbrs[num(4,4)][U] = (num(3,4), False)
nbrs[num(4,4)][R] = (None, False)
nbrs[num(4,4)][D] = (None, False)
nbrs[num(4,4)][L] = (num(4,3), False)

for node in nbrs:
  for dir in range(0, 4):
    print(node_str(node), urdl[dir], node_str(nbrs[node][dir][0]), nbrs[node][dir][1])

path = "ihgpwlah" #"kglvqrro" #"ihgpwlah"

q = deque()
start = (num(0,0), path)
q.append(start)
prev = defaultdict(tuple)
prev[start] = None

while len(q) > 0:
  cur_node, cur_path = q.popleft()
  for dir in range(0,4):
    nbr_node, nbr_door = nbrs[cur_node][dir]
    if nbr_node is not None:
      if not nbr_door or is_open(dir, cur_path):
        nbr_path = cur_path + urdl[dir]
        if nbr_node == 16:
          print(cur_path)
          exit(1)
        q.append((nbr_node, nbr_path))
        
