import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from functools import reduce
from operator import xor
import math
import numpy as np


def to_arr(grid):
  return np.array([list(row) for row in grid])

def to_list(arr):
  return [''.join(row) for row in arr]

def print_arr(arr):
  for r in to_list(arr):
    print(r)
  print("-")

def tran_match(arr, target):
  for k in range(4):
    arr = np.rot90(arr, 1)
    if np.array_equal(arr, target):
      return True
    arr2 = np.fliplr(arr)
    if np.array_equal(arr2, target):
      return True
  return False

def transform(arr, rules):
  for L, R in rules:
    if tran_match(arr, L):
      return R
  return arr

def enhance(arr, rules):
  n = arr.shape[0]
  ts = 2 if n % 2 == 0 else 3
  nt = n // ts  
  print(n, ts, nt)
  enh = np.full((nt * (ts + 1), nt * (ts + 1)), ".", dtype=str)
  for i in range(0, nt):
    for j in range(0, nt):
      ra = i * ts
      ca = j * ts
      tile = arr[ra:ra+ts, ca:ca+ts]
      tile_enh = transform(tile, rules)
      re = i * (ts + 1)
      ce = j * (ts + 1)
      enh[re:re+(ts+1), ce:ce+(ts+1)] = tile_enh
  return enh

def main():
  rules = []
  for line in sys.stdin:
    #print(line)
    rule = line.strip().split(" => ")
    pat = rule[0].strip().split("/")
    res = rule[1].strip().split("/")
    rules.append((to_arr(pat), to_arr(res)))
  
  # starting grid
  grid = [
    ".#.", 
    "..#", 
    "###"
  ]  
  arr = to_arr(grid)
  for k in range(18): 
    print(k, arr.shape[0]) 
    arr = enhance(arr, rules)

  print(np.count_nonzero(arr == "#"))

if __name__ == "__main__":
  main()
    