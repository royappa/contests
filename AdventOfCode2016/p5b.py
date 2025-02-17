import sys
from collections import defaultdict
import hashlib

seed = "cxdnnyjw"

index=0
passwd="________"
while True:
  index += 1
  s = seed+str(index)
  hash = hashlib.md5(s.encode()).hexdigest()
  if hash[0:5] == "00000":
    print(hash)
    pch = hash[5]
    if not pch.isdigit() or pch > '7':
      continue
    pos = ord(pch)-ord('0')
    if passwd[pos] != '_':
      continue
    passwd = passwd[:pos] + hash[6] + passwd[pos+1:]
    print(passwd)
    if passwd.find("_") == -1:
      sys.exit(0)

