import sys
import re
from collections import defaultdict
from collections import Counter

import hashlib

def aba(s):
  n = len(s)
  return {t for t in [s[i:i+3] for i in range(0, n-2)] if t[0] == t[2] and t[0] != t[1]}

tot = 0
for line in sys.stdin:
  inside = re.findall(r"\[(.*?)\]", line.strip())
  outside = re.split(r"\[.*?\]", line.strip())
  aba_outside = set().union(*map(aba, outside))
  aba_outside_rev = set(map(lambda s : s[1]+s[0]+s[1], aba_outside))
  aba_inside = set().union(*map(aba, inside))
  if aba_outside_rev & aba_inside:
    tot += 1

print(tot)
 
    
