import sys

lines = [line.strip() for line in sys.stdin]
pad = {
    '1': "__3_",
    '2': "_36_",
    '3': "1472",
    '4': "__83",
    '5': "_6__",
    '6': "27A5",
    '7': "38B6",
    '8': "49C7",
    '9': "___8",
    'A': "6B__",
    'B': "7CDA",
    'C': "8__B",
    'D': "B___"
}
dirs = "URDL"
cur = '5'
for line in lines:
  for dir in line:
    i = dirs.index(dir)
    go = pad[cur][i]
    if (go != '_'):
      cur = go
  print(cur)
    
