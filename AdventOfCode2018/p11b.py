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
  
  gridsums = np.zeros((301, 301), dtype=int)
  for y in range(1, 301):
    for x in range(1, 301):
      gridsums[y, x] = gridsums[y-1, x] + gridsums[y, x-1] - gridsums[y-1, x-1] + grid[y, x]
  m = float('-inf')
  for r in range(1, 300):
    for y in range(1, 301-r+1):
      for x in range(1, 301-r+1):
        ny = y + r - 1
        nx = x + r - 1
        a = gridsums[ny, nx]
        b = gridsums[ny-r, nx-r]
        c = gridsums[ny, nx-r]
        d = gridsums[ny-r, nx]
        s = a - b - c - d + 2*b
        if s > m:
          m = s
          my = y
          mx = x
          mr = r

  print(f"{mx},{my},{mr}")

if __name__ == "__main__":
  main()
