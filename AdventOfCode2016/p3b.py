import sys

data = [[int(w) for w in line.split()] for line in sys.stdin]
nums = [num for list in list(map(list, zip(*data))) for num in list]
        

tot = sum(t[0]+t[1] > t[2] for t in [sorted(nums[i:i+3]) for i in range(0, len(nums), 3)])
                            
print(tot)
