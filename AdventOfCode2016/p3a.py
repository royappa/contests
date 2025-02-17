import sys

tot = 0
for line in sys.stdin:
  t = sorted(map(int, line.split()))
  if t[0]+t[1] > t[2]:
    tot += 1
print(tot)



    
