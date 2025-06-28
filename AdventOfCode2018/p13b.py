import sys
from collections import defaultdict
import numpy as np
import re
import string
from llist import dllist
 
def move(y, x, c, cm, paths):
  delta = dict()
  delta = {"^": (-1, 0), ">": (0, 1), "v": (1, 0), "<": (0, -1)}
  y2, x2 = delta[c]
  y2 += y
  x2 += x
  track = paths[(y2, x2)]
  turns = dict()
  turns["/"] = {"^":">" , ">":"^" , "v": "<", "<":"v"}
  turns["\\"] = {"^":"<" , ">":"v" , "v": ">", "<":"^" }
  turns["+"] = True
  c2 = c
  cm2 = cm
  if track in "/\\":
    c2 = turns[track][c]
  elif track in "-|":
    pass
  else:
    right = {"^":">" , ">":"v" , "v": "<", "<":"^"}
    left =   {"^":"<" , "<":"v" , "v": ">", ">":"^" }
    c2 = left[c] if cm == 0 else right[c] if cm == 2 else c
    cm2 = (cm + 1) % 3
  return (y2, x2, c2, cm2)

def main():
  lines = [line.rstrip() for line in sys.stdin]
  paths = dict()
  carts = dict()
  next = dict()
  h = 0
  w = 0
  for y, line in enumerate(lines):
    h = max(h, y)
    for x, c in enumerate(line):
      w = max(w, x)
      paths[(y, x)] = c
      if c in "^>v<":
        carts[(y, x)] = c
        next[(y, x)] = 0
        paths[(y, x)] = "-" if c in {"<", ">"} else "|"
  h += 1
  w += 1
  n = len(carts)
  last = [0] * n
  while len(carts) > 1:
    print(len(carts))
    carts2 = dict()
    next2 = dict()
    a = [[" "] * w for _ in range(h)]
    for y, x in paths:
      a[y][x] = paths[(y, x)]
    for y, x in carts:
      a[y][x] = carts[(y, x)]
    #for i, r in enumerate(a):
    #  print(i, "".join(r)[0:100])
    #print("*")
    L = sorted(carts.copy())
    dele = set()
    for y, x in L:  
      if (y, x) in dele:
        continue  
      c = carts[(y, x)]
      del carts[(y, x)]
      y2, x2, c2, cm2 = move(y, x, c, next[(y, x)], paths)
      #print(y, x, c, next[(y, x)], " -> ", y2, x2, c2, cm2)
      if (y2, x2) in carts2 or (y2, x2) in carts:
        dele.add((y2, x2))
        if (y2, x2) in carts2:
          del carts2[(y2, x2)]
          del next2[(y2, x2)]
        if (y2, x2) in carts:
          del carts[(y2, x2)]
          del next[(y2, x2)]
      else:
        carts2[(y2, x2)] = c2
        next2[(y2, x2)] = cm2
      #print(len(carts) + len(carts2))
    carts = carts2.copy()
    next = next2.copy()
  print(carts)
if __name__ == "__main__":
  main()
