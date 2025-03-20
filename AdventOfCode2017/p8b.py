import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy


m = float('-inf')
prog = []
for line in sys.stdin:
  exec(line.split()[0]+"=0")
  prog.append(line.strip())

for line in prog:
  reg = line.split()[0]
  line = line.replace("inc", "+=").replace("dec", "-=") + " else 0"
  print(line)
  exec(line)
  exec(f"m = max(m, {reg})")  

print(m)




  




