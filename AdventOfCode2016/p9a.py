import sys
import re
from collections import defaultdict
from collections import Counter
import hashlib

lines = [line for line in sys.stdin]
s = "".join(line.strip() for line in lines)

tot = 0
while len(s) > 0:
  match = re.search(r"(.*?)\((\d+)x(\d+)\)(.*)", s)
  if match:
    tot += len(match.group(1))
    a = int(match.group(2))
    b = int(match.group(3))
    tot += a*b
    s = match.group(4)[a:]
  else:
    tot += len(s)
    s = ""

print(tot)
 
    
