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
x = 0
y = 1
z = 2
r = 3
vx = 4
vy = 5
vz = 6
n = int(input())
ans = 0
for i in range(n):
    c = list(map(int,input().split()))
    j = list(map(int,input().split()))
    if math.sqrt(pow(c[x]-j[x],2)+pow(c[y]-j[y],2)+pow(c[z]-j[z],2))<c[r]+j[r]:
        print(format(0,'.3f'))
        continue
    '''
    to1 = pow(c[x],2) + pow(j[x],2) - 2*c[x]*j[x] + pow(c[y],2) + pow(j[y],2) - 2*c[y]*j[y]+ pow(c[z],2) + pow(j[z],2) - 2*c[z]*j[z] - c[r] - j[r]
    to2 = 2*c[x]*c[vx]-2*c[x]*j[vx]-2*j[x]*c[vx]-2*j[x]*j[vx] + 2*c[y]*c[vy]-2*c[y]*j[vy]-2*j[y]*c[vy]-2*j[y]*j[vy]
    +2*c[z]*c[vz]-2*c[z]*j[vz]-2*j[z]*c[vz]-2*j[z]*j[vz]
    to3 = pow(c[vx],2)+pow(j[vx],2)-2*c[vx]*j[vx]+ pow(c[vy],2)+pow(j[vy],2)-2*c[vy]*j[vy]+ pow(c[vz],2)+pow(j[vz],2)-2*c[vz]*j[vz]
    '''
    to1 = pow(c[vx]-j[vx],2)+pow(c[vy]-j[vy],2)+pow(c[vz]-j[vz],2)
    to2 = 2*((c[vx]-j[vx])*(c[x]-j[x])+(c[vy]-j[vy])*(c[y]-j[y])+(c[vz]-j[vz])*(c[z]-j[z]))
    to3 = pow(c[x]-j[x],2)+pow(c[y]-j[y],2)+pow(c[z]-j[z],2)-pow(c[r]+j[r],2)
    if to1 == 0:
        if to2 == 0:
            if to3 == 0:
                ans = 0
            else:
                ans = -1
        if (-to3*to2 > 0):
            ans = -to3/to2
        else:
            ans == -1
    elif pow(to2,2)-4*to1*to3 < 0:
        ans = -1
    elif (-to2 - math.sqrt(abs(pow(to2,2)-4*to1*to3)))/(2*to1) > 0:
        ans = (-to2 - math.sqrt(abs(pow(to2,2)-4*to1*to3)))/(2*to1) 
    elif (-to2 + math.sqrt(abs(pow(to2,2)-4*to1*to3)))/(2*to1) > 0:
        ans = (-to2 + math.sqrt(abs(pow(to2,2)-4*to1*to3)))/(2*to1)
    else:
        ans = -1
    
    if ans<0:
        print("No collision")
    else:
        print(format(ans,'.3f'))
    