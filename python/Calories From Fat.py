import re

calories = [9,4,4,4,7]
Total_list = []
group_list = []
tt = 0
c_total = 0
count = 0

while True:
    
    meal = list(map(str,input().split()))
    Total_list.append(meal)
    
    if meal[0] == "-" :
        
        group_list.append(count)
        if Total_list[count-1][0] == '-':
            break  
    count += 1
    
    
for m in range(len(Total_list)):
    
    cal = 0   
    mark = 0
    total = 0
    calculations = []
    
    if Total_list[m][0] != "-":
        
        for i in range(len(Total_list[m])):
            
            if "g" in Total_list[m][i]:
                
                n = re.sub("\D","",Total_list[m][i])
                calculations.append(str(int(n)*calories[i]))
            if "C" in Total_list[m][i]:
                
                n = re.sub("\D","",Total_list[m][i])
                calculations.append(n)
            if "%" in Total_list[m][i]:
                
                calculations.append(Total_list[m][i])
        for i in range(len(calculations)):

            if calculations[i].isdigit() :
                
                total+=int(calculations[i])
                if i == 0:
                    
                    c_total += int(calculations[i])
                    
            else:
                
                n = re.sub("\D","",calculations[i])
                cal += int(n)
                if i == 0:
                    
                    mark = int(n)                
                
                    
        total += (total/((100-cal)/100)) * cal/100
        tt += total
        c_total += (mark/100)*total  
        
    else:
        if Total_list[m+1][0] == "-":
            res = format(c_total/tt, '.0%')
            print(res)            
            break
        else:
                       
            res = format(c_total/tt, '.0%')
            print(res)
            tt = 0
            c_total = 0             
