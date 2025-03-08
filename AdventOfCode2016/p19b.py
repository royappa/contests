import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

num = int(sys.argv[1])
print("elves = ", num)
prev = defaultdict(int)
next = defaultdict(int)

for i in range(1, num+1):
  prev[i] = i-1 if i > 1 else num
  next[i] = i+1 if i < num else 1

cur = 1
opp = num // 2 + 1

print(cur)
n = num
while n > 2:
  left = (n - 2) // 2
  right = (n - 2) - left
  #print("Before: ", "num =", n, "cur = ", cur, "opp = ", opp, "left = ", left, "right = ", right)
  #print(prev, next)
  cur = next[cur]
  old_opp = opp
  if left == right:
    temp = prev[opp]
    opp = next[opp]
    next[temp] = opp
    prev[opp] = temp
  else:
    temp = prev[opp]
    skip = next[opp]
    next[temp] = skip
    prev[skip] = temp
    opp = next[skip]
  
  del prev[old_opp]
  del next[old_opp]
  #print("After: ", "num =", n, "cur = ", cur, "opp = ", opp, "left = ", left, "right = ", right)
  #print(prev, next)
  #print("***")
  n = n - 1

print(cur, next, prev) # one of these two is the right one.. too lazy for end condition coding
