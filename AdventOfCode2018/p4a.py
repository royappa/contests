import sys
from collections import defaultdict
import numpy as np
import re

def main():
  L = sorted([line.strip() for line in sys.stdin])
  state = 0
  slept = defaultdict(int)
  slept_min = defaultdict(int)
  for w in L:
    nums = list(map(int, re.findall(r"\d+", w)))
    if len(nums) == 6:
      id = nums[5]
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
  max_sleep = max(slept.values())
  mm0 = -1
  min_best = -1
  id_best = -1
  for id, s in slept.items():
    if s == max_sleep:
      mm = -1
      kk = -1
      for k in range(0, 60):
        if slept_min[(id, k)] > mm:
          mm = slept_min[(id,k)]
          kk = k
      if mm > mm0:
        mm0 = mm
        id_best = id
        min_best = kk
  print(id_best, min_best)
  print(id_best * min_best)
      
if __name__ == "__main__":
  main()


  



