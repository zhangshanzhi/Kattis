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
t = int(input())

def exgcd(a, b):     
    if b == 0:         
        return 1, 0, a     
    else:         
        x, y, q = exgcd(b, a % b)        
        x, y = y, (x - (a // b) * y)         
        return x, y, q
    
for i in range(t):
    kids, candy = map(int,input().split())

    if candy == 1:
        print(kids+1)
        continue
    if kids == 1 and candy >1:
        print(1)
        continue
   
    x,y,d = exgcd(kids,candy)
    if d == 1:
        print((y%kids+kids)%kids)
    else:
        print("IMPOSSIBLE")

        
     