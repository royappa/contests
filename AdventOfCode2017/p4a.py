import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

tot = 0
for line in sys.stdin:
  words = line.strip().split()
  swords = set(words)
  tot += len(words) == len(swords)

print(tot)




