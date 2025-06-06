import sys
from collections import defaultdict
import numpy as np
import re
import string
import copy

def all_prereq(before, step):
  all_before = before[step]
  if len(all_before) == 0:
    return all_before
  full = all_before.copy()
  for prev in all_before:
    full.update(all_prereq(before, prev))
  return full

def cost(let, delta):
  return 1 + ord(let) - ord("A") + delta

def is_ready(step, done, all_before):
  return all(pre in done for pre in all_before[step])

def main():
  before = defaultdict(set)
  steps = set()
  for line in sys.stdin:
    w = line.split()
    before[w[7]].add(w[1])
    steps.update([w[1], w[7]])

  all_before= defaultdict(set)
  for step in steps:
    all_before[step] = all_prereq(before, step)

  #for step in steps:
  #  print(step, all_before[step])
  
  working, ready = [], []
  done = [step for step in steps if all_before[step] == []]
  waiting = [step for step in steps if all_before[step] != []]
  num_workers = 5
  delta = 60

  time = 0
  while len(done) != len(steps):
    ready += [step for step in waiting if all(prev in done for prev in all_before[step])]
    waiting = [step for step in waiting if not all(prev in done for prev in all_before[step])]
    while len(working) < num_workers and len(ready) > 0:
      step = ready[0]
      ready = ready[1:]
      working += [(step, cost(step, delta))]
    working = [(step, delta - 1) for step, delta in working]
    done += [step for (step, delta) in working if delta == 0]
    working = [(step, delta) for (step, delta) in working if delta > 0]
    time += 1

  print(time)

if __name__ == "__main__":
  main()


  



