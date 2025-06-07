import sys
from collections import defaultdict
import numpy as np
import re
import string

def f(it):
  nc, nm = next(it), next(it)
  values = [f(it) for _ in range(nc)]
  ind = [next(it) for _ in range(nm)]  
  if nc == 0:
    return sum(ind)
  return sum(values[i-1] for i in ind if i-1 in range(nc))
  
def main():
  it = map(int, sys.stdin.readline().split())
  
  print(f(it))

if __name__ == "__main__":
  main()


  



