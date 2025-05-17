import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor
import math
import numpy as np


def main():
  grid = [line.strip() for line in sys.stdin]
  h, w = len(grid), len(grid[0])
  orig = defaultdict(lambda: "C")
  orig.update({(r, c) : "I" for r in range(h) for c in range(w) if grid[r][c] == "#"})
  status = orig.copy()
  r = h // 2
  c = w // 2
  print(r, c)
  burst = 0
  inf_count = 0
  dir = 0 # U = 0, R = 1, D = 2, L = 3

  dirs = [-1, 0, 0, 1, 1, 0, 0, -1]
  while burst < 10000000:
    if status[(r, c)] == "C":
      dir = (dir - 1) % 4
      status[(r, c)] = "W"
    elif status[(r, c)] == "W":
      status[(r, c)] = "I"
      inf_count = inf_count + 1
    elif status[(r, c)] == "I":
      dir = (dir + 1) % 4
      status[(r, c)] = "F"
    else: # Flagged
      dir = (dir - 2) % 4
      status[(r, c)] = "C"
    r += dirs[2*dir]
    c += dirs[2*dir+1]
    burst += 1
  print(inf_count)

if __name__ == "__main__":
  main()
    