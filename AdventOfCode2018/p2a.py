import sys
from collections import defaultdict

# part 1:  awk ' { s += $1; } END { print s } ' < foo

# part 2
def main():
  L = [line.strip() for line in sys.stdin]
  n2 = n3 = 0
  for s in L:
    hist = defaultdict(int)
    for c in list(s):
      hist[c] += 1
    n2 += 2 in hist.values()
    n3 += 3 in hist.values()
  print(n2 * n3)

if __name__ == "__main__":
  main()


  



