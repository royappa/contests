import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor


def get_val(v, regs):
  return regs[v] if v.isalpha() else int(v)

def main():
  prog = [line.strip().split() for line in sys.stdin]
  regs = defaultdict(int)
  regs["a"] = 1

  num_mul = 0
  pc = 0
  while pc < len(prog):
    print(pc)
    instr = prog[pc]
    opcode, op1, op2 = instr
    op2_val = get_val(op2, regs)
    if opcode == "set":
      regs[op1] = op2_val
    elif opcode == "sub":
      regs[op1] -= op2_val
    elif opcode == "mul":
      regs[op1] *= op2_val
      num_mul += 1
    else:
      if get_val(op1, regs) != 0:
        pc += op2_val
        pc -= 1
    pc += 1
  print(num_mul)

if __name__ == "__main__":
  main()

  



