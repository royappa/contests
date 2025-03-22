import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

tot = 0

def capture(m):
  global tot
  tot += len(m.group()) - 2
  return ""

for line in sys.stdin:
  s = re.sub(r"<[^>]*>", capture, re.sub(r"!.", "", line.strip()))
print(tot)




  




