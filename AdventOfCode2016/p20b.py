import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

last = 4294967295
intervals = sorted([list(map(int, line.split("-"))) for line in sys.stdin])

end = 0
tot = 0
for (a,b) in intervals:
  print(end, "[", a,b, "]")
  if a <= end+1:
    if b > end:
      end = b
  else:
    tot = tot + (a - end - 1)
    end = b

tot += last - end
print(tot)
