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

def compute_hash(s):
    all_hash_value[s] = {}
    p = 31
    m = 1e9 + 9 # some large prime number
    hash_value = 0
    p_pow = 1
    all_hash_value[s][-1] = 0
    for i in range(len(s)):
        hash_value = (hash_value + (ord(s[i]) - ord('a') + 1) * p_pow) % m
        p_pow = (p_pow * p) % m
    return hash_value

def sub_hash(s):
    p = 31
    m = 1e9 + 9
    sub_hash = []
    p_inverse = modInverse(p, m)
    for i in range(len(s)): # delete i from s
        first = all_hash_value[s][i-1]
        second = (all_hash_value[s][len(s)-1] - all_hash_value[s][i]) * p_inverse
        sub_hash.append((first + second) % m)
        if s[i] == 'g':
            print("second", second)
            print((first + second) % m)
    return sub_hash

n = int(input())
all_word = {}
word = []
for i in range(n):
    word = input()
    sc = compute_hash(word)
    word.append(sc)
for i in word:
    sub = sub_hash(i)
    