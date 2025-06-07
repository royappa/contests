import sys
from collections import defaultdict
import numpy as np
import re
import string

def f(it):
  nc, nm = next(it), next(it)
  return sum(f(it) for _ in range(nc)) + sum(next(it) for _ in range(nm))
  
def main():
  it = map(int, sys.stdin.readline().split())
  
  print(f(it))

if __name__ == "__main__":
  main()


  



