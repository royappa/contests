import sys
from collections import defaultdict
import numpy as np
import re
import string
from llist import dllist
 

def main():
  serial = int(sys.argv[1])

  grid = np.zeros((301, 301), dtype=int)
  for y in range(1, 301):
    for x in range(1, 301):
      rack_id = x + 10
      p = rack_id * y
      p += serial
      p *= rack_id
      p //= 100
      p %= 10
      p -= 5
      grid[y, x] = p
  
  m = max(np.sum(grid[y:y+3, x:x+3]) for y in range(1, 298) for x in range(1, 298))
  best = [(y, x) for y in range(0, 298) for x in range(0, 298) if np.sum(grid[y:y+3, x:x+3]) == m]
  print(m)
  print(best)

if __name__ == "__main__":
  main()


  



