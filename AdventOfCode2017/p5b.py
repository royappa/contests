import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

mem = [int(line) for line in sys.stdin]
pc = 0
steps = 0
while pc >= 0 and pc < len(mem):
  opc = pc
  pc += mem[pc]
  mem[opc] += -1 if mem[opc] >= 3 else 1
  steps += 1

print(steps)




