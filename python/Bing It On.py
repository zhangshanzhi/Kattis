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
class Trie:
 
    def __init__(self):
        self.root = {}
 
    def insert(self, word):
        
        cur_Node = self.root
        for c in word:
            if not c in cur_Node:
                cur_Node[c] = {"times":1}
            else:
                cur_Node[c]["times"] += 1
            cur_Node = cur_Node[c]

 
    def search(self, word):

        cur_Node = self.root
        num = 0
        for c in word:
            if not c in cur_Node:
                return False,0
            num = cur_Node[c]["times"]
            cur_Node = cur_Node[c]
        return True,num
 
N = int(input())
trie_tree = Trie()
for i in range(N):
    
    word = input()
    param_2,times = trie_tree.search(word)
    print(times)
    trie_tree.insert(word)
    