import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

tot = 0
for line in sys.stdin:
  s = re.sub(",", "", re.sub(r"<[^>]*>", "", re.sub(r"!.", "", line.strip())))
  level = 0
  score = 0
  for c in s:
    if c == "{":
      level = level + 1
      score += level
    else:
      level = level - 1
  print(score)
  tot += score
print(tot)




  




