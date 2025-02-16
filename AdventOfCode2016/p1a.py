import sys
line = sys.stdin.readline().strip()
v = line.split(", ")
x, y = 0,0
cur = 0 # north
dirs = [0,1, 1,0, 0,-1, -1,0]
visited = {(0,0)}
for w in v:
  dir, steps = w[:1], int(w[1:])
  if dir == 'R':
    cur = (cur + 1) % 4
  else:
    cur = (((cur - 1) % 4) + 4) % 4
  dx, dy = dirs[cur*2], dirs[cur*2+1]
  x += dx*steps
  y += dy*steps
  if (x,y) in visited:
    print(x,y)
    break
  visited |= {(x,y)}

print(abs(x) + abs(y))

  