cases = input()
ans_sheet = []

for i in range(int(cases)):
    
    pole_length,ants = map(int,input().split())
    pos = []
    num = 0 
    max_num = 0
    min_num = 0    
    
    while num < ants:
        
        pos += list(map(int,input().split()))
        num = len(pos) 
        
    for i in pos:
        min_num = max( min_num , min(i,pole_length-i) );
        max_num = max( max_num , max(i,pole_length-i) );
        
    ans_sheet.append([min_num,max_num])
    
for i in ans_sheet:
    for j in i:
        print(j,end=' ')
    print("")