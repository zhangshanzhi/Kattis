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

def fibonacci(n):
    if n == 0:
        return 0
    if n == 1 or n == 2:
        ret[str(n)] = 1
        return ret[str(n)]
    if n in ret:
        return ret[n]
    if n % 2 == 0:
        cal = n/2
        ret[n] = fibonacci(cal)*(fibonacci(cal)+2*fibonacci(cal-1))
        ret[n]%=mod
    else:
        cal = (n+1)/2
        ret[n] = fibonacci(cal)*fibonacci(cal)+fibonacci(cal-1)*fibonacci(cal-1)
        ret[n]%=mod
    return ret[n]

for _ in range(int(input())):
    mod = pow(10,9)
    ret = dict()
    a,b = map(int,input().split())
    print(a,fibonacci(b))