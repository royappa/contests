import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from itertools import permutations

import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from itertools import permutations

import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def is_int(s):
  try:
    int(s)
    return True
  except ValueError:
    return False

def run(prog, a, num):
  output = []
  regs = [a, 0, 0, 0]
  pc = 0
  while pc < len(prog):
    opcode, p1, p2, n1, n2 = prog[pc]
    if opcode == "cpy":
      if not n2:
        regs[p2] = p1 if n1 else regs[p1]
      pc += 1
    elif opcode == "inc":
      if not n1:
        regs[p1] += 1
      pc += 1
    elif opcode == "dec":
      if not n1:
        regs[p1] -= 1
      pc += 1
    elif opcode == "out":
      output.append(p1 if n1 else regs[p1])
      pc += 1
    else: # jnz
      if (p1 if n1 else regs[p1]) != 0:
          pc += p2 if n2 else regs[p2]
      else:
        pc += 1
    if len(output) >= num:
      break
  return output 

prog = []
for line in sys.stdin:
  instr = line.strip().split()
  opcode = instr[0]
  if opcode == "tgl":
    p1 = int(instr[1]) if is_int(instr[1]) else ord(instr[1][0]) - ord('a')
    p2 = -1
  elif opcode == "cpy":
    p1 = int(instr[1]) if is_int(instr[1]) else ord(instr[1][0]) - ord('a')
    p2 = ord(instr[2][0]) - ord('a')
  elif opcode == "inc" or instr[0] == "dec":
    p1 = ord(instr[1][0]) - ord('a')
    p2 = -1
  elif opcode == "jnz":
    p1 = int(instr[1]) if is_int(instr[1]) else ord(instr[1][0]) - ord('a')
    p2 = int(instr[2]) if is_int(instr[2]) else ord(instr[2][0]) - ord('a')
  elif opcode == "out":
    p1 = int(instr[1]) if is_int(instr[1]) else ord(instr[1][0]) - ord('a')
    p2 = -1    
  prog.append((opcode, p1, p2, is_int(instr[1]), True if len(instr) >= 3 and is_int(instr[2]) else False))

a = int(sys.argv[1])
num = int(sys.argv[2])
output = run(prog, a, num)  
o = "".join(list(map(str, output)))
print(o)
exit(1)
a = 0
num = 10
while True:
  output = run(prog, a, num)  
  o = "".join(list(map(str, output)))
  if o == "0101010101":
    print(a)
    break
  a = a + 1






 
    
