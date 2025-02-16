import sys

lines = [line.strip() for line in sys.stdin]
pad = {
    1: "_24_",
    2: "_351",
    3: "__62",
    4: "157_",
    5: "2684",
    6: "3_95",
    7: "48__",
    8: "59_7",
    9: "6__8"
}
dirs = "URDL"
cur = 5
for line in lines:
  for dir in line:
    i = dirs.index(dir)
    where = pad[cur][i]
    if (where != '_'):
      cur = int(where)
  print(cur)
    
