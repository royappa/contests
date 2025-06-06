import sys
from collections import defaultdict
import numpy as np
import re
import string

def mdist(y1, x1, y2, x2):
  return abs(y1 - y2) + abs(x1 - x2)

def under(y, x, pts, val):
  s = sum(map(lambda p : mdist(y, x, p[0], p[1]), pts))
  return s < val
  
def main():
  pts = [tuple(map(int, re.findall(r"\d+", line))) for line in sys.stdin]
  min_x = min(pts, key = lambda p : p[0])[0]
  min_y = min(pts, key = lambda p : p[1])[1]
  if min_x > 1:
    pts = [(x-(min_x-1), y) for x, y in pts]
  if min_y > 1:
    pts = [(x, y-(min_y-1)) for x, y in pts]
  max_x = max(pts, key = lambda p : p[0])[0]
  max_y = max(pts, key = lambda p : p[1])[1]
  pts = [(y, x, i + 1) for i, (x, y) in enumerate(pts)]

  arr = np.zeros((max_y + 2, max_x + 2), dtype=int)

  for y in range(max_y + 2):
    for x in range(max_x + 2):
      arr[y, x] = under(y, x, pts, 10000)

  #print(arr)
  print(np.sum(arr == 1))

if __name__ == "__main__":
  main()


  



