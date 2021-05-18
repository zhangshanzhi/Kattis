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
def get_next(li,n,nex):
    i = 0
    k = -1
    while(i<n):
        if k < 0 or li[i] == li[k]:
            i+=1
            k+=1            
            nex[i] = k
        else:
            k = nex[k]
    return nex
              
ip = int(input())
line1 = list(map(int,input().split()))
line2 = list(map(int,input().split()))
line1.sort()
line2.sort()
line1_cal = [0]*(2*ip-1)
line2_cal = [0]*ip
next_i = [0]*ip
next_i[0] = -1
flag = 0
round_deg = 360000
for i in range(1,ip):
    line1_cal[i-1] = line1[i] - line1[i-1]
line1_cal[ip-1] = (line1[0]-line1[-1]+round_deg)%round_deg
for i in range(ip,2*ip-1):
    line1_cal[i] = line1[i-ip+1] - line1[i-ip]
    
for i in range(1,ip):
    line2_cal[i-1] = line2[i] - line2[i-1]
nex = get_next(line2_cal,ip-1,next_i)
i = 0
k = -1
while(i < 2*ip-1):
    if k < 0 or line1_cal[i] == line2_cal[k]:
        i+=1
        k+=1    
    else:
        k = nex[k]
    if k >= ip-1:

        flag = 1
        break
    
if flag == 1:        
    print("possible")
else:
    print("impossible")


