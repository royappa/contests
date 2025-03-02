import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

disks = []
i = 1
for line in sys.stdin:
  r = re.match(r".+has (\d+).+position (\d+)", line)
  print("t +", i + int(r.group(2)), " mod ", r.group(1), " = 0")
  i = i + 1

# feed to any Chinese Remainder Theorem solver