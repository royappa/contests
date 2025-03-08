import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

orig_num = 3001330
e = [i for i in range(1, orig_num+1)]
  
while len(e) > 1:
  rot = len(e) % 2
  e = e[0::2]
  if rot:
    e = e[-1:] + e[:-1]
print(e[0])
