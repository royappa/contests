import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def dump(state, ne, elts, finish=True):
  lets = [str.upper(e[0:1]) for e in elts]
  cur, floors = state[0], list(state[1])
  sfloors = []
  for i, floor in enumerate(floors):
    a = reversed(f"{floor[0]:0{ne}b}")
    b = reversed(f"{floor[1]:0{ne}b}")
    aout = ["."] * ne
    for j, c in enumerate(a):
      if c == "1": aout[j] = lets[j]
    bout = ["."] * ne
    for j, c in enumerate(b):
      if c == "1": bout[j] = lets[j]
    sfloors.append("".join(aout)+"".join(bout)+("*" if i == cur else " "))
  if finish:
    print(sfloors)
    #print("+"*(2*ne))
  else:
    print(sfloors, " ", end="")

def dump_path(cur, ne, elts):
  if cur == None:
    return
  dump_path(prev[cur], ne, elts)
  dump(cur, ne, elts)

#elts = ["lithium", "hydrogen"]
elts = ["cobalt", "curium", "plutonium", "promethium", "ruthenium"]
floors_list = []
types = ["generator", "microchip"]
ne = len(elts)
i = 0
for line in sys.stdin:
  m = re.findall(r"(\S+?) (generator|microchip)", line.replace("-compatible", ""))
  masks = [0,0]
  for elt,type in m:
    ei, ti = elts.index(elt), types.index(type)
    masks[ti] |= (1<<ei)
  print(line, f"{masks[0]:0{ne}b}", f"{masks[1]:0{2}b}")
  floors_list.append(tuple(masks))

dist = defaultdict(int)
start = (0,  tuple(floors_list))
prev = {}
prev[start] = None
print(start)
dump(start, ne, elts)
q = deque([start])
dist[start] = 0
while len(q) > 0:
  cur = q.popleft()
  # print("pop: ", end="")
  # dump(cur, ne, elts)
  cur_floor, cur_floors_state = cur[0], list(cur[1])
  if cur_floor == 3 and sum(x.bit_count() for x in cur_floors_state[3]) == 2*ne:
    print("Done", dist[cur], cur_floor, cur_floors_state)
    dump_path(cur, ne, elts)
    exit(1)
  for adj_floor in range(0,4):
    if abs(adj_floor-cur_floor) != 1: continue
    cur_gens, cur_chips = cur_floors_state[cur_floor]
    #if adj_floor < cur_floor and cur_floors_state[adj_floor][0]+cur_floors_state[adj_floor][1] == 0: continue
    for g in range(0, 1<<ne):
      for c in range(0, 1<<ne):
        if not ((g&cur_gens) == g and (c&cur_chips) == c): continue
        if (g.bit_count()+c.bit_count()) == 0 or (g.bit_count()+c.bit_count()) > 2: continue
        cur_gens_new = cur_gens & ~g
        cur_chips_new = cur_chips & ~c
        if cur_gens_new and not ((cur_chips_new & cur_gens_new) == cur_chips_new): continue
        adj_gens, adj_chips = cur_floors_state[adj_floor]
        adj_gens_new = adj_gens | g
        adj_chips_new = adj_chips | c
        if adj_gens_new and not ((adj_chips_new & adj_gens_new) == adj_chips_new): continue
        adj_floors_state = copy.deepcopy(cur_floors_state)
        adj_floors_state[cur_floor] = (cur_gens_new, cur_chips_new)
        adj_floors_state[adj_floor] = (adj_gens_new, adj_chips_new)
        adj = (adj_floor, tuple(adj_floors_state))
        if not adj in dist:
          dist[adj] = dist[cur] + 1
          prev[adj] = cur
          q.append(adj)
          # dump(cur, ne, elts, False)
          # dump(adj, ne, elts, False)
          # print()

print("end")
 
    
