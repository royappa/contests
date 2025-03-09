import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

intervals = []
for line in sys.stdin:
  m = re.match(r"(\d+)-(\d+)", line)
  intervals.append(list(map(int, m.groups())))

end = 0
for (a,b) in sorted(intervals):
  print(end, "[", a,b, "]")
  if a <= end+1:
    if b > end:
      end = b
  else:
    print(end+1)
    exit(1)