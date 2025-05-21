import sys
from collections import defaultdict
import numpy as np
import re
import string


def f(s):
  p = "("
  for ch in string.ascii_lowercase:
    uch = ch.upper()
    p += f"|{ch}{uch}|{uch}{ch}"
  p += ")"
  return re.sub(p, "", s)
  
def f2(line):
  line2 = f(line)
  while line2 != line:
    line = line2
    line2 = f(line)
  return line2

def main():
  line = sys.stdin.read().strip()
  best = 1000000
  for ch in string.ascii_lowercase:
    uch = ch.upper()
    d = line.replace(ch, "").replace(uch, "")
    best = min(best, len(f2(d)))
    print(ch)
  print(best)
  
if __name__ == "__main__":
  main()


  



