import sys
from collections import defaultdict
import numpy as np
import re
import string

def mdist(y1, x1, y2, x2):
  return abs(y1 - y2) + abs(x1 - x2)

def closest(y, x, pts):
  s = sorted(pts, key = lambda p : mdist(y, x, p[0], p[1]))
  return 0 if mdist(y, x, s[0][0], s[0][1]) == mdist(y, x, s[1][0], s[1][1]) else s[0][2]
  
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
      arr[y, x] = closest(y, x, pts)

  all = set(range(1, len(pts)+1))
  edge = set()
  edge.update(arr[0, :])
  edge.update(arr[:, 0])
  edge.update(arr[max_y+2-1, :])
  edge.update(arr[:, max_x+2-1])
  print(max([np.sum(arr == v) for v in all - edge]))

if __name__ == "__main__":
  main()


  



