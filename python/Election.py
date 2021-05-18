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

def fac(m,n):
    return math.factorial(m)//(math.factorial(n)*math.factorial(m-n))

T = int(input())
for i in range(T):
    N, V1, V2, W = map(int,input().split())
    
    if N - V2 > V2:
        if N%2 == 0:
            need = (N//2) + 1
            r = need - V1
        else:
            need = math.ceil(N/2)
            r = need - V1
        if r < 0:
            r = 0
            
        pro = 0
        rest = N-V2-V1
        flag = 0
        for i in range(r,rest+1):
            pro += fac(rest,i)*pow(0.5,rest)
            if pro*100 > W:
                flag = 1
                break
        if flag == 1:
            print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
            continue
        print("PATIENCE, EVERYONE!")
    else:
        print("RECOUNT!")