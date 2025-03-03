import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def ck(s):
  while len(s)%2 == 0:
    s = "".join(["1" if s[k:k+1] == s[k+1:k+2] else "0" for k in range(0, len(s), 2)])
  return s

a = "10111011111001111"
while len(a) < 272:
  b = ["0" if x == "1" else "1" for x in reversed(a)]
  a = a + "0" + ("".join(b))

print("".join(ck(a[0:272])))