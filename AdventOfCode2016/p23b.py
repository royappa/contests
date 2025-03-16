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

def modify(prog, pc, off):
  pc += off
  if pc < 0 or pc >= len(prog):
    return
  opcode, p1, p2, n1, n2 = prog[pc]
  if opcode == "inc":
    opcode = "dec"
  elif opcode in ["dec", "tgl"]:
    opcode = "inc"
  elif opcode == "jnz":
    opcode = "cpy"
  elif opcode == "cpy":
    opcode = "jnz"
  else:
    print("oops")
    exit(1)
  prog[pc] = (opcode, p1, p2, n1, n2)
  print(pc, off, prog[pc])

regs = [8,0,0,0] # value of c changes for parts a,b
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
  prog.append((opcode, p1, p2, is_int(instr[1]), True if len(instr) >= 3 and is_int(instr[2]) else False))

print(prog)
pc = 0
while pc < len(prog):
  opcode, p1, p2, n1, n2 = prog[pc]
  if pc == 10:
    print("pc: ", pc, "op: ", opcode, p1, p2, n1, n2, "mem: ", regs)
  if opcode == "tgl":
    modify(prog, pc, p1 if n1 else regs[p1])
    pc += 1
  elif opcode == "cpy":
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
  else: # jnz
    if (p1 if n1 else regs[p1]) != 0:
        pc += p2 if n2 else regs[p2]
    else:
      pc += 1
  #print(regs)
  #print("---")

print(regs[0])
 
    
