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
  print(f(parts, 0, 0, 1))

if __name__ == "__main__":
  main()

  



