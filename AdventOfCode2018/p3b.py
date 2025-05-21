import sys
from collections import defaultdict
import numpy as np
import re

def main():
  grid = np.empty((1000, 1000), dtype=object)
  for x in range(1000):
    for y in range(1000):
      grid[x,y] = set()

  ids = set()
  for line in sys.stdin:
    nums = list(map(int, re.findall(r"\d+", line)))
    id, x, y, w, h = nums
    ids.add(id)
    print(x, y, w, h)
    # arrays of objects apparently don't have nice array-subrange ops :-(
    for i in range(x, x+w):
      for j in range(y, y+h):
        grid[i, j].add(id)
  
  # slow .. O(n^3) where n ~ 1000, took few mins
  dup_ids = { id for id in ids for x in range(1000) for y in range(1000) if len(grid[x,y]) > 1 and id in grid[x,y] }
  rem_ids = ids - dup_ids
  print(list(rem_ids)[0])
  
if __name__ == "__main__":
  main()


  



