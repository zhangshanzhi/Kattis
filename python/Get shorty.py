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
import heapq 
import sys

while True:
    
    inp = sys.stdin.readline().strip()
    if inp == '':
        break
    n, m = map(int,inp.split())
    if m == n == 0:
        continue  
    weights = [[math.inf,True] for i in range(n)]
    graph = dict()
    weights[0][0] = -1
    for i in range(m):
        x,y,f = input().split()
        if x in graph:
            graph[x].append((y,f))
        else:
            graph[x] = [(y,f)]
        if y in graph:
            graph[y].append((x,f))
        else:
            graph[y] = [(x,f)]
            
    point = 0
    ans = 0
    con = []  

    while True:
        if point == n-1:
            print(format(abs(ans),'.4f'))
            break   
        weights[point][1] = False
        for i in graph[str(point)]:       
            if weights[int(i[0])][1]: 
                ss= weights[point][0]*float(i[1])
                if float(ss) < float(weights[int(i[0])][0]) :                   
                    weights[int(i[0])][0] = ss
                if weights[int(i[0])][0] > 0:
                    heapq.heappush(con,(-weights[int(i[0])][0],int(i[0])))
                else:
                    heapq.heappush(con,(weights[int(i[0])][0],int(i[0])))

        it = heapq.heappop(con)
        point = it[1]
        ans = it[0]
                
