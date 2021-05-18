n = input()
line = list(map(int,input().split()))

order = [1]

for i in range(int(n)-1):
    line[i] = (line[i], i+2)
    
line.sort()

for i in range(int(n)-1):
    order.append(line[i][1])
    
for i in order:
    print(i, end = ' ')