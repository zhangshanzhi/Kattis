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

def isPrimes(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True

T = int(input())
for i in range(T):
    
    N,D = map(int,input().split())
    start_point = (0,0)
    cor_list = []
    counts = 0
    ans = 0
    for i in range(N):
        co = tuple(map(int,input().split()))
        cor_list.append(co)
    for i in range(N):
        x = cor_list[i][0]
        y = cor_list[i][1]
        total_m = math.sqrt(pow(start_point[0]-x,2) + pow(start_point[1]-y,2))
        D -= total_m
        if D < 0:
            break    
        elif D == 0:
            counts += 1
            if isPrimes(counts) and counts != 1:
                ans = counts
            break  
        start_point = (x,y)
        counts += 1
        if isPrimes(counts) and counts != 1:
            ans = counts 

    print(ans)
        
        