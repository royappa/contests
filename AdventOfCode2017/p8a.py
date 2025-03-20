import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

prog = ""
vars = set()
for line in sys.stdin:
  line = line.strip()
  w = line.split()
  vars.add(w[0])
  line = line.replace("inc", "+=").replace("dec", "-=")
  line += " else 0;"
  prog += line

zero = "=".join(vars) + "=0;"
prog = zero + prog
maxes = "print(max(" + ",".join(vars) + "))"
prog += maxes
print(prog)
exec(prog)




  




