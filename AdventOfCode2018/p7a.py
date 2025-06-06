import sys
from collections import defaultdict
import numpy as np
import re
import string


def main():

  before = defaultdict(set)
  steps = set()
  for line in sys.stdin:
    w = line.split()
    before[w[7]].add(w[1])
    steps.update([w[1], w[7]])
  
  order = ""
  while len(steps):
    for step in sorted(steps):
      if len(before[step]) == 0:
        order += step
        for k in before:
          if step in before[k]:
            before[k].remove(step)
        steps.remove(step)
        break
  print(order)

if __name__ == "__main__":
  main()


  



