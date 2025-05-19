import sys
from collections import defaultdict


def main():
  steps = 12794428
  state = dict()
  state[("A", 0)] = (1,  1, "B")
  state[("A", 1)] = (0, -1, "F")

  state[("B", 0)] = (0,  1, "C")
  state[("B", 1)] = (0,  1, "D")

  state[("C", 0)] = (1,  -1, "D")
  state[("C", 1)] = (1,   1, "E")

  state[("D", 0)] = (0,  -1, "E")
  state[("D", 1)] = (0,  -1, "D")

  state[("E", 0)] = (0,  1, "A")
  state[("E", 1)] = (1,  1, "C")

  state[("F", 0)] = (1, -1, "A")
  state[("F", 1)] = (1,  1, "A")

  tape = defaultdict(int)
  cur_state = "A"
  pos = 0
  n = 0
  while n < steps:
    symbol, delta, cur_state = state[(cur_state, tape[pos])]
    tape[pos] = symbol
    pos += delta
    n += 1
  checksum = sum(v for v in tape.values() if v != 0)
  print(checksum)
if __name__ == "__main__":
  main()


  



