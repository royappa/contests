import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def num(r, c):
  return r*5 + c

def node_str(n):
  return None if n is None else str(n // 5) + "," + str(n % 5)

def get_hash(s):
  return hashlib.md5(s.encode()).hexdigest()

def is_open(door, passwd):
  m = [0,3,1,2][door]
  hash = get_hash(passwd)
  # print(hash[:4])
  return hash[m] >= "b" and hash[m] <= "f" 

def dfs(cur, depth, urdl, nbrs):
  pad = "." * depth
  cur_node, cur_path = cur
  # print(pad, node_str(cur_node), cur_path)
  if cur_node == 24:
    print(depth)
    return
  doors = 0
  for dir in range(0,4):
    nbr_node, nbr_door = nbrs[cur_node][dir]
    if nbr_node is not None:
      if not nbr_door or is_open(dir, cur_path):
        doors = doors + 1
        nbr_path = cur_path + urdl[dir]
        dfs((nbr_node, nbr_path), depth+1, urdl, nbrs)


nbrs = defaultdict(lambda: [None] * 4)
U,R,D,L = 0,1,2,3
urdl = "URDL"

for r in range(0,5):
  for c in range(0,5):
    if r == 4 or c == 4: continue
    node = r*5 + c
    print(r, c, node_str(node), num(r, c))
    nbrs[node][U] = (num(r-1, c), True) if r > 0 else (None, False) 
    nbrs[node][R] = (num(r, c+1), True) if c < 3 else (None, False)
    nbrs[node][D] = (num(r+1, c), True) if r < 3 else (None, False)
    nbrs[node][L] = (num(r, c-1), True) if c > 0 else (None, False)
   
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

print(3, 4, node_str(num(3, 4)), num(3,4))
print(4, 3, node_str(num(4, 3)), num(4,3))
print(4, 4, node_str(num(4, 4)), num(4,4))
for node in nbrs:
  for dir in range(0, 4):
    print(node_str(node), urdl[dir], node_str(nbrs[node][dir][0]), nbrs[node][dir][1])

path = "ihgpwlah" # "ihgpwlah" #"edjrjqaa" #"edjrjqaa" #"kglvqrro" 

start = (num(0,0), path)

q = deque()
start = (num(0,0), path)
q.append(start)
prev = defaultdict(tuple)
prev[start] = None

while len(q) > 0:
  cur_node, cur_path = q.popleft()
  print("Cur:", node_str(cur_node), cur_path)
  if cur_node == 24:
    print(node_str(cur_node), len(cur_path) - len(path), cur_path[len(path):])  
  for dir in range(0,4):
    nbr_node, nbr_door = nbrs[cur_node][dir]
    if nbr_node is not None:
      if not nbr_door or is_open(dir, cur_path):
        nbr_path = cur_path + urdl[dir]
        q.append((nbr_node, nbr_path))