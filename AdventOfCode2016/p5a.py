import sys
from collections import defaultdict
import hashlib

seed = "cxdnnyjw"

index=0
passwd=""
while True:
  index += 1
  s = seed+str(index)
  hash = hashlib.md5(s.encode()).hexdigest()
  if hash[0:5] == "00000":
    print(hash)
    passwd += hash[5]
    print(passwd)
    if len(passwd) == 8:
      sys.exit(0)

