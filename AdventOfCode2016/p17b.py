import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def num(r, c):
  return r*4 + c

def node_str(n):
  return None if n is None else str(n // 4) + "," + str(n % 4)

def get_hash(s):
  return hashlib.md5(s.encode()).hexdigest()

def is_open(door, passwd):
  m = [0,3,1,2][door]
  hash = get_hash(passwd)
  # print(hash[:4])
  return hash[m] >= "b" and hash[m] <= "f" 

nbrs = defaultdict(lambda: [None] * 4)
U,R,D,L = 0,1,2,3
urdl = "URDL"

for r in range(0,4):
  for c in range(0,4):
    node = r*4 + c
    print(r, c, node_str(node), num(r, c))
    nbrs[node][U] = (num(r-1, c), True) if r > 0 else (None, False) 
    nbrs[node][R] = (num(r, c+1), True) if c < 3 else (None, False)
    nbrs[node][D] = (num(r+1, c), True) if r < 3 else (None, False)
    nbrs[node][L] = (num(r, c-1), True) if c > 0 else (None, False)
   
for node in nbrs:
  for dir in range(0, 4):
    print(node_str(node), urdl[dir], node_str(nbrs[node][dir][0]), nbrs[node][dir][1])

path = "edjrjqaa" # "ihgpwlah" #"edjrjqaa" #"edjrjqaa" #"kglvqrro" 

start = (num(0,0), path)

q = deque()
start = (num(0,0), path)
q.append(start)
prev = defaultdict(tuple)
prev[start] = None

while len(q) > 0:
  cur_node, cur_path = q.popleft()
  # print("Cur:", node_str(cur_node), cur_path)
  if cur_node == 15:
    print(node_str(cur_node), len(cur_path) - len(path), cur_path[len(path):])
    continue
  for dir in range(0,4):
    nbr_node, nbr_door = nbrs[cur_node][dir]
    if nbr_node is not None:
      if not nbr_door or is_open(dir, cur_path):
        nbr_path = cur_path + urdl[dir]
        q.append((nbr_node, nbr_path))