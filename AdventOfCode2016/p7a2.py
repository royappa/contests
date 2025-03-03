import sys
import re
from collections import defaultdict
from collections import Counter

import hashlib

def pat(s):
  n = len(s)
  return any((sub == sub[::-1] and sub[0] != sub[1])
             for sub in [s[i:i+4] for i in range(0, n-3)])
tot = 0
for line in sys.stdin:
  inside = re.findall(r"\[(.*?)\]", line.strip())
  outside = re.split(r"\[.*?\]", line.strip())
  tot += any(pat(x) for x in outside) and not any(pat(x) for x in inside)
print(tot)
 
    
