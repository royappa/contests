import sys
import re
from collections import defaultdict
from collections import Counter
import hashlib

filename = sys.argv[1]
with open(filename, "r") as file:
  lines = file.readlines()

h,w = 6,50
grid = [[0]*w for _ in range(h)]

for line in lines:
  a,b = list(map(int,re.findall(r"\d+", line)))
  print(a, b, ": ", line)
  if line[0:4] == "rect":
    for r in range(b):
      grid[r][0:a] = [1]*a
  elif line[7] == 'r':
    grid[a] = grid[a][-b:] + grid[a][:-b]
  else:
    col = [grid[r][a] for r in range(h)]
    col_rev = col[-b:] + col[:-b]
    for r,v in enumerate(col_rev):
      grid[r][a] = v
  for row in grid:
    print("".join("." if v == 0 else "x" for v in row))
  #input("hit")
tot = sum(map(sum, grid))
print(tot)
 
    
