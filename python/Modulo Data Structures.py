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
import sys
N,Q = map(int,sys.stdin.readline().strip("\n").split())
sep = math.ceil(math.sqrt(N))
arr = [0]*(N+1)
bucket = [[0]*(sep+1) for i in range(sep+1)]
for i in range(Q):
    ip = list(map(int,sys.stdin.readline().strip("\n").split()))
    if ip[0] == 1:
        A = ip[1]
        B = ip[2]
        C = ip[3]
        if B <= sep:
            bucket[B][A] += C
        else:
            for j in range(A,N+1,B):
                arr[j] += C
    else:
        D = ip[1]
        ss = arr[D]
        for i in range(1,sep+1):
            ss += bucket[i][D%i]
        print(ss)