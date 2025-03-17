import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def foo(L):
  return [x // y for x in L for y in L if x != y and x%y == 0][0]

LL = [list(map(int, line.split())) for line in sys.stdin]
tot = sum([foo(L) for L in LL])

print(tot)