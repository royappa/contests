import sys
from collections import defaultdict
import numpy as np
import re
import string
from llist import dllist
 

def main():
  initial = sys.stdin.readline().split()[2]
  sys.stdin.readline()

  rules = defaultdict()
  for line in sys.stdin:
    rule = line.strip().split()
    rules[rule[0]] = rule[2]
  
  offset = 200
  cur = ("." * offset) + initial + ("." * offset)
  n = len(cur)

  m = 0
  for gen in range(200):
    next = ["."] * n
    for i in range(2, n-2):
      s = cur[i-2:i+3]
      next[i] = "#" if s in rules and rules[s] == "#" else "."
    cur_pos = [i - offset if c == "#" else 0 for i, c in enumerate(next)]
    next_s = "".join(next)
    if cur.strip(".") == next_s.strip(".") and m < 3:
      print(m, gen, cur)
      print(sum(cur_pos))
      m += 1    
    cur = "".join(next)

  # manually do the rest  
  #print(sum(cur_pos))

if __name__ == "__main__":
  main()
