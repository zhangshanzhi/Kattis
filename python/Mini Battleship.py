"""
  <Your Name> Shanzhi Zhang
  <Student ID #> 1541578

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  <List Resources Here>

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  <List Classmates Here>

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""
import itertools

def col_to_row(arr, n):
    res = [[row[i] for row in arr] for i in range(n)]
    return res

def calculate(board,ship,size,num,cct,sidee,sidd):
    e_c1 = []
    e_c2 = []
    total_list = []  
    re_board = col_to_row(board,size)
    sample = []
    
    for i in board:
        e_c1.append([(k,len(list(v))) for k,v in itertools.groupby(i)])
    
    for i in re_board:
        e_c2.append([(k,len(list(v))) for k,v in itertools.groupby(i)])
        
    yy = len(ship)-1
    while yy >= 0:
        
        sp = ship[yy]
        sp_list = []
        total1 = 0
        total2 = 0
        if sp == 1:
            sp_list = sidd
        else:
            for i in range(len(e_c1)):
                for j in e_c1[i]:
                    if j[0] == 0:
                        if j[1] >= sp:
                            cc = j[1] - sp + 1
                            temp = total1
                            for u in range(cc):
                                s1d = [k for k in range(temp,temp+sp)]
                                if s1d not in sp_list:
                                    sp_list.append([k for k in range(temp,temp+sp)])
                                temp += 1
                            total1 += j[1]
                        else:
                            total1+=j[1]
                    else:
                        total1 += j[1]
                        
                total2=i
                for j in e_c2[i]:
                    if j[0] == 0:
                        if j[1] >= sp:
                            cc = j[1] - sp + 1
                            temp = total2
                            for u in range(cc):
                                s2d = [k for k in range(temp,temp+sp*size,size)]
                                if s2d not in sp_list:
                                    sp_list.append([k for k in range(temp,temp+sp*size,size)])
                                temp += size
                            total2 += j[1]*size
                        else:
                            total2+=j[1]*size
                    else:
                        total2 += j[1]*size
           
        total_list.append(sp_list)
        yy-=1
  
    for i in total_list[0]:
        sample.append(i)
        x = 1          
        while x <= num-1:
            a = []
            for uu in range(len(total_list[x])):
                for xxx in sample:
                    if len(xxx) < cct:
                        g = [m for m in total_list[x][uu] if m in xxx]
                        if g == []:
                            a.append(xxx+total_list[x][uu])
            sample+=a
            ddd = 0
            while True:
                if ddd == len(sample):
                    break
                ccce = len(sample[-1])
                if len(sample[ddd]) < ccce:
                    del sample[ddd]
                    ddd -= 1
                ddd+=1
            x+=1
            
    final_cc = len(sample)
    
    for i in sample:
        for j in sidee:
            if j not in i:
                final_cc -= 1
                break
        
    return final_cc
  
size,num = input().split()
cal_board= []
ship = []
sidee = []
sidd = []
for i in range(int(size)):
    line = input()
    cal_board.append([])
    for j in range(len(line)):
        if line[j]=='.':
            sidd.append(i*int(size)+j)
            cal_board[i].append(0)
        elif line[j] == 'O':
            sidee.append(i*int(size)+j)
            cal_board[i].append(0)
        elif line[j]== 'X':
            cal_board[i].append(-1)
print(sidd)
   
for i in range(int(num)):
    ship.append(int(input()))
ship.sort()

cct = 0
for i in ship:
    cct+=i
count = calculate(cal_board,ship,int(size),int(num),cct,sidee,sidd)
print(count)