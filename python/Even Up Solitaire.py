class Stack(object):
    def __init__(self, mylist = []):
        self.stack = mylist
    
    def push(self, item):
        return self.stack.append(item)
    
    def pop(self):
        return self.stack.pop()
    
    def peek(self):
        return self.stack[len(self.stack) - 1]
    
    def size(self):
        return len(self.stack)
    
number_of_element = input()
list_of_cards = list(map(int,input().split(" ")))

stack_element = Stack()
for i in range(int(number_of_element)-1,-1,-1):
    if(stack_element.size() != 0):
        if(list_of_cards[i] + stack_element.peek() )%2 == 0:
            stack_element.pop()
        else:
            stack_element.push(list_of_cards[i])
    else:
        stack_element.push(list_of_cards[i])
            
print(stack_element.size())

        