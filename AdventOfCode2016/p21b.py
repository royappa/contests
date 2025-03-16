import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy
from itertools import permutations

def scramble(str, lines):
  s = list(str)
  for line in lines:
    if (m := re.match(r"swap position (\w+) with position (\w+)", line)):
      a, b = map(int, m.groups())
      s[a], s[b] = s[b], s[a]
    elif (m := re.match(r"swap letter (\w+) with letter (\w+)", line)):
      a, b = map(s.index, m.groups())
      s[a], s[b] = s[b], s[a]
    elif (m := re.match(r"rotate left (\w+) step\w?", line)):
      k = int(m.group(1))
      s = s[k:] + s[0:k]
    elif (m := re.match(r"rotate right (\w+) step\w?", line)):
      k = int(m.group(1))
      s = s[-k:] + s[0:-k]
    elif (m := re.match(r"rotate based on position of letter (\w+)", line)):
      p = s.index(m.group(1))
      k = (1 + p + (1 if p >= 4 else 0)) % len(s)
      s = s[-k:] + s[0:-k]
    elif (m := re.match(r"reverse positions (\w+) through (\w+)", line)):
      a, b = map(int, m.groups())
      s = s[:a] + list(reversed(s[a:b+1])) + s[b+1:]
    elif (m := re.match(r"move position (\w+) to position (\w+)", line)):
      a, b = map(int, m.groups())
      c = s[a]
      del s[a]
      s = s[0:b] + [c] + s[b:]
    else:
      print("oops")
    str = "".join(s)
  return str

lines = [line.strip() for line in sys.stdin]
scram = sys.argv[1]
for passwd in permutations(list(scram)):
  if scramble(passwd, lines) == scram:
    print("".join(passwd))
    exit(1)
print("oops2")

