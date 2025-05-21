import sys
from collections import defaultdict
import numpy as np
import re

def f(s):
  for i in range(len(s)-1):
    if s[i].upper() == s[i+1].upper() and s[i].isupper() != s[i+1].isupper():
      return s[:i] + s[i+2:]
  return s
  
def main():
  line = sys.stdin.read().strip()
  line2 = f(line)
  while line2 != line:
    line = line2
    line2 = f(line)
  print(len(line2))
if __name__ == "__main__":
  main()


  



