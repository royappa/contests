import sys
from collections import defaultdict
from collections import Counter

import hashlib

data = [line.strip() for line in sys.stdin]
n = len(data[0])
code = ""
for c in range(0, n):
  col = [row[c] for row in data]
  counter = Counter(col)
  code += counter.most_common(1)[0][0]
print(code)