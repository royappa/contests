import sys
from collections import defaultdict
import numpy as np
import re

def main():
  L = sorted([line.strip() for line in sys.stdin])
  state = 0
  slept = defaultdict(int)
  slept_min = defaultdict(int)
  guards = set()
  for w in L:
    nums = list(map(int, re.findall(r"\d+", w)))
    if len(nums) == 6:
      id = nums[5]
      guards.add(id)
      state = 1
    elif state == 1:
      start = nums[4]
      state = 0
    else:
      end = nums[4]
      dt = tuple(nums[:3])
      #print("guard ", id, "slept for", end - start, "on", dt)
      slept[id] += end - start
      for m in range(start, end):
        slept_min[(id, m)] += 1
      state = 1

  best_id, best_min = max(slept_min, key=slept_min.get)

  print(best_id * best_min)
if __name__ == "__main__":
  main()


  



