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

class Tree:
    def __init__(self,n):
        self.n = n  
        self.li = [0]*n
    def update(self,j,val):
        while j < self.n:
            self.li[j] += val
            j |= j+1
    def rqs(self,it):
        total = 0
        while it >= 0:
            total+=self.li[it]
            it = (it&(it+1))-1
        return total
    def calt(self,i,j):
        return self.rqs(j)-self.rqs(i-1)
            
N,Q = map(int,sys.stdin.readline().strip("\n").split())
V = list(map(int,sys.stdin.readline().strip("\n").split()))
char = list(sys.stdin.readline().strip("\n"))
tree = Tree(6)
for i in range(6):
    tree.li[i] = Tree(N+1)
for i in range(N):
    tree.li[ord(char[i])-ord("1")].update(i,1)
for i in range(Q):
    a,k,p = map(int,sys.stdin.readline().strip("\n").split())
    if a == 1:
        tree.li[ord(char[k-1])-ord("1")].update(k-1,-1)
        char[k-1] = chr(ord('0')+p)
        tree.li[ord(char[k-1])-ord("1")].update(k-1,1)
    elif a == 2:
        V[k-1] = p
    else:
        total = 0
        for j in range(6):
            total += tree.li[j].calt(k-1,p-1)*V[j]
        print(total)


