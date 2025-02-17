import sys
from collections import defaultdict

def shift(c, num):
  i = ord(c)-ord('a')
  i = (i+num)%26
  return chr(ord('a')+i)

for line in sys.stdin:
  name, rest = line.rsplit("-", 1)
  id, csum = int(rest[:rest.find("[")]), rest[rest.find("[")+1:rest.rfind("]")]
  new_name = "".join(shift(c,id) for c in name)
  if new_name == 'northpolefobjectfstorage':
    print(id)
  #print(new_name)  # for printing all names

                           

