import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def check(cur, num, x, y):
  if cur == num:
    print(num, "MDist = ", abs(x)+abs(y))
    exit(0)

num = int(sys.argv[1])

n = 1
x = 0
y = 0
cur = 1
check(cur, num, x, y)
while True:
  n += 2
  x += 1
  cur += 1
  check(cur, num, x, y)
  for _ in range(0, n-2):
    y += 1
    cur += 1
    check(cur, num, x, y)
  for _ in range(0, n-1):
    x -= 1
    cur += 1
    check(cur, num, x, y)
  for _ in range(0, n-1):
    y -= 1
    cur += 1
    check(cur, num, x, y)
  for _ in range(0, n-1):
    x += 1
    cur += 1
    check(cur, num, x, y)

  




