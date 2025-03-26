import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor

a = int(sys.argv[1])
b = int(sys.argv[2])

amul = 16807
bmul = 48271
modulus = 2147483647

tot = 0
for _ in range(0, 40000000):
  a = (a * amul) % modulus
  b = (b * bmul) % modulus
  tot += (a % (1<<16)) == (b % (1<<16))
print(tot)