import sys
from collections import defaultdict
import numpy as np
import re

def main():
  grid = np.zeros((1000, 1000))
  for line in sys.stdin:
    nums = list(map(int, re.findall(r"\d+", line)))
    x, y, w, h = nums[1:5]
    print(x, y, w, h)
    grid[x:x+w, y:y+h] += 1
  print(np.count_nonzero(grid > 1))
  
if __name__ == "__main__":
  main()


  



