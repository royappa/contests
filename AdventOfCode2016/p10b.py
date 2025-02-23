import sys
import re
from collections import defaultdict
from collections import Counter
import hashlib

bots = set()
outputs = {}
inputs = defaultdict(list)
values = defaultdict(list)
def get_value(bot, which):
  if len(values[bot]) < 2:
    for inp in inputs[bot]:
      srcbot, ind = inp
      values[bot].append(get_value(srcbot, ind))
  return sorted(values[bot])[which]

  
# bot 2 gives low to bot 1 and high to bot 0
# value 3 goes to bot 1
# bot 0 gives low to output 2 and high to output 0


for line in sys.stdin:
  # print(line.strip())
  if line[0] == "v":
    m = re.search(r"value (\d+) goes to bot (\d+)", line.strip())
    chip,bot = map(int, m.groups())
    bots.add(bot)
    values[bot].append(chip)
  else:
    m = re.search(r"bot (\d+) gives low to (\S+) (\d+) and high to (\S+) (\d+)", line.strip())
    srcbot, low, lownum, high, highnum = (int(m.group(1)), m.group(2), int(m.group(3)), m.group(4), int(m.group(5)))
    bots.add(srcbot)
    if low == "bot":
      bots.add(lownum)
      inputs[lownum].append((srcbot, 0))
    else:
      print("output", lownum)
      bots.add(1000+lownum)
      inputs[1000+lownum].append((srcbot, 0))
    if high == "bot":
      bots.add(highnum)
      inputs[highnum].append((srcbot, 1))
    else:
      print("output", highnum)
      bots.add(1000+highnum)
      inputs[1000+highnum].append((srcbot, 1))     

for bot in bots:
  print(bot, "inputs: ", inputs[bot], "values: ", get_value(bot, 0), get_value(bot, 1))

tot = 0
print(tot)
 
    
