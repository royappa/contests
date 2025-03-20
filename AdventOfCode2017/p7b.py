import sys
import re
from collections import defaultdict
from collections import Counter, deque
import hashlib, copy

def walk(root, tree, weights):
  children = tree[root]
  w = weights[root]
  if len(children) == 0:
    return w
  L = []
  for c in children:
    L.append(walk(c, tree, weights))
  if L != sorted(L):
    counted = Counter(L)
    odd = min(counted, key = counted.get)
    for c in children:
      if odd == walk(c, tree, weights):
        print(c, weights[c])
    print(root, weights[node], children, L)
  return w + sum(L)  

weights = defaultdict(int)
tree = defaultdict(list)
nodes = set()
internal = set()
for line in sys.stdin:
  m = re.match(r"(\w+) \((\d+)\)( -> )?(.+)?", line.strip())
  node, weight, children = m.group(1), int(m.group(2)), m.group(4).split(", ") if m.group(4) is not None else []
  weights[node] = weight
  tree[node] = children
  nodes.add(node)
  internal.update(children)

root = list(nodes-internal)[0]

w = walk(root, tree, weights) # answer is in top 2 lines of output


  




