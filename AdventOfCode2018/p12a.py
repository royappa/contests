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
  
  offset = 100
  initial = ("." * offset) + initial + ("." * offset)

  n = len(initial)
  for _ in range(20):
    next = ["."] * n
    for i in range(2, n-2):
      s = initial[i-2:i+3]
      next[i] = "#" if s in rules and rules[s] == "#" else "."
    initial = "".join(next)

  r = min(i - offset for i, c in enumerate(initial) if c == "#")
  print(r)
  r = max(i - offset for i, c in enumerate(initial) if c == "#")
  print(r)
if __name__ == "__main__":
  main()
