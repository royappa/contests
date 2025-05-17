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
  orig = {(r, c) for r in range(h) for c in range(w) if grid[r][c] == "#"}
  inf = orig.copy()
  r = h // 2
  c = w // 2
  print(r, c)
  print(orig)
  burst = 0
  inf_count = 0
  dir = 0 # U = 0, R = 1, D = 2, L = 3

  dirs = [-1, 0, 0, 1, 1, 0, 0, -1]
  while burst < 10000:
    #print("on", r, c)
    if (r, c) in inf:
      dir = (dir + 1) % 4
      #print("cl", r, c)
      inf.remove((r, c))
    else:
      dir = (dir - 1) % 4
      inf.add((r, c))
      #print("in", r, c)
      #if (r, c) not in orig:
      inf_count = inf_count + 1
    r += dirs[2*dir]
    c += dirs[2*dir+1]
    burst += 1
    #print(r, c)
  print(inf_count)

if __name__ == "__main__":
  main()
    