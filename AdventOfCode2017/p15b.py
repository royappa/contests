import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

oa = int(sys.argv[1])
ob = int(sys.argv[2])

amul = 16807
bmul = 48271
modulus = 2147483647

tot = 0
ka = 0
kb = 0
a = oa
b = ob
for i in range(0, 5000000):
  while True:
    a = (a * amul) % modulus
    if a % 4 == 0:
      break
  while True:
    b = (b * bmul) % modulus
    if b % 8 == 0:
      break
  tot += (a % (1<<16)) == (b % (1<<16))
  if i % 100000 == 0:
    print(i)
print(tot)