import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor


grid = []
for line in sys.stdin:
  grid.append(line.rstrip("\r\n"))
nr, nc = len(grid), len(grid[0])
dir_sym = dict()
dir_sym[0] = dir_sym[2] = "|"
dir_sym[1] = dir_sym[3] = "-"
opp = dict()
opp["|"] = "-"
opp["-"] = "|"
grid2 = grid[:]

def good(r, c):
  return (0 <= r < nr) and (0 <= c < nc) and grid[r][c] != " "
  
def next_pos(cr, cc, dir):
  dirs = [(-1,0), (0,1), (1,0), (0,-1)]  #URDL
  if grid[cr][cc] in {"-", "|"} or grid[cr][cc].isalpha():
    r = cr + dirs[dir][0]
    c = cc + dirs[dir][1]
    if good(r, c):
      return (r, c, dir)
    return None
  # we are on a +
  for d in [(dir + 1) % 4, (dir + 3) % 4]:
    r = cr + dirs[d][0]
    c = cc + dirs[d][1]    
    if good(r, c) and (grid[r][c] == dir_sym[d] or grid[r][c].isalpha()):
      return (r, c, d)
  return None


dir = 2
r = 0
c = grid[0].find("|")
letters = ""

dir_tok = "^>v<"
grid2[r] = grid2[r][:c] + dir_tok[dir] + grid2[r][c+1:]
#print("\n".join(grid2))
while True:
  #print(r, c, dir)  
  pos = next_pos(r, c, dir)
  if pos == None:
    break
  r, c, dir = pos
  grid2[r] = grid2[r][:c] + dir_tok[dir] + grid2[r][c+1:]
  #print("\n".join(grid2))  
  if grid[r][c].isalpha():
    letters += grid[r][c]
  print(letters)
  