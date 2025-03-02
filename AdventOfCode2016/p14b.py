import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

salt = "zpqevtbw"
keys = []
poss_keys = []
i = 0
while len(keys) < 64:
  val = salt + str(i)
  hash = hashlib.md5(val.encode()).hexdigest()
  for stretch in range(0, 2016):
    hash = hashlib.md5(hash.encode()).hexdigest()
  n = len(hash)
  triples = set()
  quints = set()
  slen = 0
  cur = "."
  for j in range(0, n):
    if hash[j] == cur:
      slen += 1
    else:
      slen = 1
      cur = hash[j]
    if slen >= 3 and len(triples) == 0:
      triples.add(cur)
    if slen >= 5:
        quints.add(cur)
  if len(quints) > 0:
    print(i, hash, "quints: ", quints)
    del_list = []
    for j in range(len(poss_keys)):
      if quints & poss_keys[j][2]:
        keys.append((poss_keys[j][0], poss_keys[j][1], i))
        print("key#:", len(keys), ": ", i, poss_keys[j][1], poss_keys[j][0])
        del_list.append(j)
    for ind in reversed(del_list):
      del poss_keys[ind]

  if len(triples) > 0:
    print(i, hash, "triples: ", triples)
    poss_keys.append((i, hash, triples))
  for j in range(len(poss_keys)-1, -1, -1):
    if i == poss_keys[j][0] + 1000:
      print(i, hash, "expired: ", poss_keys[j][0])
      del poss_keys[j]
  i += 1

for i, x in enumerate(sorted(keys)):
  print(i+1, x)
 
    
