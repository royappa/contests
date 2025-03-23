import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

delta = {"n": (0,2), "nw": (-1,1), "ne": (1,1), "se": (1,-1), "s": (0,-2), "sw": (-1,-1)}

for line in sys.stdin:
  cur = (0,0)
  m = 0
  for step in line.strip().split(","):
    dr, dc = delta[step]
    cur = (cur[0] + dr, cur[1] + dc)
    m = max(m, int((abs(cur[0])+abs(cur[1]))/2))  # would fail for ne,se. Need to adjust distance formula
    # check https://www.redblobgames.com/grids/hexagons/ for help
  print(cur, m)




