import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

regs = [0,0,1,0] # value of c changes for parts a,b
prog = []
for line in sys.stdin:
  instr = line.strip().split()
  opcode = instr[0]
  if opcode == "cpy":
    if instr[1].isnumeric():
      opcode = "cpyn"
      val = int(instr[1])
    else:
      val = ord(instr[1][0]) - ord('a')
    reg = ord(instr[2][0]) - ord('a')
  elif opcode == "inc" or instr[0] == "dec":
    val = 0
    reg = ord(instr[1][0]) - ord('a')
  elif opcode == "jnz":
    if instr[1].isnumeric():
      opcode = "jnzn"
      reg = int(instr[1])
    else:
      reg = ord(instr[1][0]) - ord('a')
    val = int(instr[2])
  prog.append((opcode, val, reg))

print(prog)
pc = 0
while pc < len(prog):
  opcode, val, reg = prog[pc]
  # print("pc: ", pc, "op: ", opcode, val, reg, "mem: ", regs)
  if opcode == "cpy":
    regs[reg] = regs[val]
    pc += 1
  elif opcode == "cpyn":
    regs[reg] = val
    pc += 1
  elif opcode == "inc":
    regs[reg] += 1
    pc += 1
  elif opcode == "dec":
    regs[reg] -= 1
    pc += 1
  elif opcode == "jnzn":
    if reg != 0:
      pc += val
    else:
      pc += 1
  else: # jnz
    if regs[reg] != 0:
      pc += val
    else:
      pc += 1

print(regs[0])
 
    
