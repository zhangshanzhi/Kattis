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
import sys
n = int(sys.stdin.readline().strip("\n"))
for i in range(n):
    s_dict = {}
    max1 = 0
    max2 = 0
    for j in range(int(sys.stdin.readline().strip("\n"))):
        w = sys.stdin.readline().strip("\n")
        if w not in s_dict:
            s_dict[w] = j
            max1+=1
        else:
            max1 = min(max1+1,j-s_dict[w])
            s_dict[w] = j
        max2 = max(max1,max2)
    print(max2)
            
