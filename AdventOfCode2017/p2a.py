import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy


#
# 
tot = sum(max(L) - min(L) for L in [list(map(int, line.split())) for line in sys.stdin])


print(tot)