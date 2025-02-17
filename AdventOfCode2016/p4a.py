import sys
import re
from collections import defaultdict

tot = 0
for line in sys.stdin:
  name, rest = line.rsplit("-", 1)
  id, csum = rest[:rest.find("[")], rest[rest.find("[")+1:rest.rfind("]")]
  hist = defaultdict(int)
  for c in name:
    if c.isalpha():
      hist[c] = hist[c] + 1
  vals = sorted(hist.items(), key=lambda x: (-x[1], x[0]))
  csum2 = "".join([t[0] for t in vals[0:5]])
  if csum == csum2:
    tot += int(id)
print(tot)
                           

