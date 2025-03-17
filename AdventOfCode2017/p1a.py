import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

tot = 0
line = sys.stdin.readline().strip()
n = len(line)
tot = sum([int(line[i]) for i in range(0, n) if line[i] == line[(i+1)%n]])
print(tot)
