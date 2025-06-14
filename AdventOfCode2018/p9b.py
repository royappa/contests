import sys
from collections import defaultdict
import numpy as np
import re
import string
from llist import dllist
 
def next(ptr, L):
  return ptr.next if ptr and ptr.next else L.first

def prev(ptr, L):
  return ptr.prev if ptr and ptr.prev else L.last

def main():
  for line in sys.stdin:
    np, last, high = map(int, re.findall(r"\d+", line))
    print(np, last, high)
    L = dllist()
    cur = L.append(0)
    cur = L.append(1)
    L.insert(2, cur)
    cur = next(cur, L)
    score = defaultdict(int)
    p = 1
    m = 2
   
    while m < last:
      n = len(L)
      m += 1
      p = (p + 1) % np
      if m % 23:
        cur = next(cur, L)
        cur = next(cur, L)
        L.insert(m, cur)
        cur = prev(cur, L)
      else:
        score[p] += m
        for _ in range(7):
          cur = prev(cur, L)
        temp = next(cur, L)
        score[p] += cur.value
        L.remove(cur)
        cur = temp
    print(max(score.values()))
    

if __name__ == "__main__":
  main()


  



