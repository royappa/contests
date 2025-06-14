import sys
from collections import defaultdict
import numpy as np
import re
import string

 
def main():
  for line in sys.stdin:
    np, last, high = map(int, re.findall(r"\d+", line))
    print(np, last, high)
    L = [0, 2, 1]
    score = defaultdict(int)
    p = 1
    m = 2
    cur_pos = 1
   
    while m < last:
      n = len(L)
      m += 1
      p = (p + 1) % np
      if m % 23:
        new_pos = (cur_pos + 2) % n
        L.insert(new_pos, m)
        cur_pos = new_pos
      else:
        score[p] += m
        del_pos = (cur_pos - 7) % n
        score[p] += L[del_pos]
        del L[del_pos]
        cur_pos = del_pos
    print(max(score.values()))
    

if __name__ == "__main__":
  main()


  



