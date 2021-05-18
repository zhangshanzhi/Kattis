name_list = []
set_pos = []
new_list = []
pos = 0
set_p = 1

while True:
    n = input()
    if n.isdigit():
        set_pos.append(pos)
    name_list.append(n)
    if n == '0':
        break
    pos += 1
    
for i in range(1,len(set_pos)):
    new_list.append("SET "+str(set_p))
    set_p+=1
    if int(set_pos[i]-set_pos[i-1]-1)%2 == 0:
        for j in range(set_pos[i-1]+1,set_pos[i],2):
            new_list.append(name_list[j])
        for c in range(set_pos[i]-1,set_pos[i-1],-2):
            new_list.append(name_list[c])
    else:
        for j in range(set_pos[i-1]+1,set_pos[i],2):
            new_list.append(name_list[j])
        for c in range(set_pos[i]-2,set_pos[i-1],-2):
            new_list.append(name_list[c]) 
            
for i in new_list:
    print(i)        
