
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

ops = ['*','+','-','/']
num = 4
di = {}

n = int(input())

for i in ops:
    for j in ops:
        for k in ops:
            if round(eval('4'+i+'4'+j+'4'+k+'4')) not in di:
                di[round(eval('4'+i+'4'+j+'4'+k+'4'))] = '4 '+i+' 4 '+j+' 4 '+k+' 4 ' +'= '+ str(round(eval('4'+i+'4'+j+'4'+k+'4')))
            
for i in range(n):
    m = int(input())
    if m in di:
        print(di[m])
    else:
        print('no solution')
            