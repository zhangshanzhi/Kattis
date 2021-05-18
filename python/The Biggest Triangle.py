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
import math
def cal_c(cor):
    return (cor[3]-cor[1],cor[0]-cor[2],cor[2]*cor[1]-cor[3]*cor[0])
def cal(cor1,cor2):
    x = cor1[2]-cor1[0]
    y = cor1[3]-cor1[1]
    k = cor2[2]-cor2[0]
    z = cor2[3]-cor2[1]

    if x*z-k*y == 0:
        return (False,0,0)
    r1 = cal_c(cor1)
    r2 = cal_c(cor2)
    #print(r1[0],r1[1],r1[2],r2[0],r2[1],r2[2])
    le1 = (r2[2]*r1[1]-r1[2]*r2[1])/(r1[0]*r2[1]-r2[0]*r1[1])
    if r1[1] == 0:
        return (True,le1,0)    
    le2 = -(r1[2]+r1[0]*le1)/r1[1]
    return (True,le1,le2)

    
n = int(input())
output = 0
table = []
for i in range(n):
    cor = list(map(int,input().split()))
    table.append(cor)
    
for i in range(n):
    for j in range(n):
        for k in range(n):
            if i != j and j!=k and i != k:
                #print(table[i],table[j],table[k])
                total = 0
                A = cal(table[i],table[j])
                B = cal(table[i],table[k])
                C = cal(table[j],table[k])
                #print(A,B,C)
                if A[0]:
                    total+=1            
                if B[0]:
                    total+=1
                if C[0]:
                    total+=1                

                if total == 3:
                    aa = math.sqrt(pow(A[1]-B[1],2)+pow(A[2]-B[2],2))
                    bb = math.sqrt(pow(B[1]-C[1],2)+pow(B[2]-C[2],2))
                    cc = math.sqrt(pow(A[1]-C[1],2)+pow(A[2]-C[2],2))
                    #print(aa+bb+cc)
                    dis = aa +bb + cc 
                    output = max(output,dis)
                    #print(output)
if output == float(0):
    print("no triangle")
else:
    print(format(output,'.10f'))
                        
                        