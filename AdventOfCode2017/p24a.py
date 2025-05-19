import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

def f(parts, conn, tot, k):
  if len(parts) == 0:
    return (k, tot)
  m = (k, tot)
  for i, (a, b) in enumerate(parts):
    if a == conn or b == conn:
      m = max(m, (k, tot+a+b))
      rest = parts[:i] + parts[i+1:]
      str = f(rest, b if a == conn else a, tot+a+b, k+1)
      m = max(m, str)
  return m

def main():
  parts = [tuple(map(int, line.strip().split("/"))) for line in sys.stdin]
  m = (0, 0)
  for i, (a, b) in enumerate(parts):
    if a == 0:
      m = max(m, (1, b))
      rest = parts[:i] + parts[i+1:]
      str = f(rest, b, a+b, 1)
      m = max(m, str)
  print(m)

if __name__ == "__main__":
  main()

  



