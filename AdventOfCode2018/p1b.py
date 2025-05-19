import sys
from collections import defaultdict

# part 1:  awk ' { s += $1; } END { print s } ' < foo

# part 2
def main():
  L = list(map(int, [line for line in sys.stdin]))
  
  freq = { 0 }
  cur = 0
  i = 0
  while True:
    cur += L[i%len(L)]
    if cur in freq:
      print(cur)
      sys.exit()
    freq.add(cur)
    i += 1
if __name__ == "__main__":
  main()


  



