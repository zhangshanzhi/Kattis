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
'''
def Decomposed_prime_factor(num):
    temp = []
    while num!=1:
        for i in range(2,int(num+1)):
            if num%i == 0:
                temp.append(i)
                num = num/i
                break
    return temp  
'''
'''
def func(n):
    
    if n == 0 or n == 1:
        return 1
    else:
        return (n * func(n - 1))
        
'''
#print(math.sqrt(2*math.pi*n) * pow(n*math.exp(-1),n))

while True:
    
    ip = sys.stdin.readline().strip()     
    if ip == '':
        break  
    n,m = map(int,ip.split())
    if m == 0:
        print(m, "does not divide", str(n) + "!")
    elif m ==1 and n ==0:
        print(m, "divides", str(n) + "!")

    else:
        low_bound = 2
        up_bound = math.sqrt(m)+1
        
        m_c = m
        n_c = n
        flag = 0
        while m_c > n_c and low_bound < up_bound:
            counts = 0
            f_level = low_bound
            while m_c % low_bound==0:
                m_c = m_c//low_bound
                counts+=1
                
            while f_level<=n_c and counts>0:
                counts -= n_c//f_level
                f_level = f_level*low_bound
                
            if counts > 0:
                flag = 1
                break
            low_bound +=1
            
        if flag == 0 and m_c <= n_c:
            print(m, "divides", str(n)+"!")
        else:
            print(m, "does not divide", str(n) + "!")
    
    
    