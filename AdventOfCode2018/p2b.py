import sys
from collections import defaultdict

def main():
  L = [line.strip() for line in sys.stdin]
  for s in L:
    for t in L:
      n = len(s)
      for i in range(n):
        if s[i] == t[i]:
          continue
        s1, s2 = s[:i], s[i+1:]
        t1, t2 = t[:i], t[i+1:]
        if s1 == t1 and s2 == t2:
          print(s1+s2)
          sys.exit()

if __name__ == "__main__":
  main()


  



