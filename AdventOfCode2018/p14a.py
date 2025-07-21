import sys
from collections import defaultdict
import numpy as np
import re
import string
from llist import dllist


def main():
  num = 880751 + 10
  scores = [3, 7]
  e = [0, 1]
  while len(scores) < num:
    s = str(scores[e[0]] + scores[e[1]])
    for c in s:
      scores.append(ord(c) - ord('0'))
    n = len(scores)
    e[0] = (e[0] + scores[e[0]] + 1) % n
    e[1] = (e[1] + scores[e[1]] + 1) % n
  print("".join(str(d) for d in scores[-10:]))

if __name__ == "__main__":
  main()
