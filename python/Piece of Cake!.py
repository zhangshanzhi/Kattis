n,h,v = map(int,input().split(" "))

ac_thick = 4
ac_length = 0
ac_width = 0

if n-h >= h:
    ac_length = n-h
    if n-v >= v:
        ac_width = n-v
    else:
        ac_width = v
else:
    ac_length = h
    if n-v >= v:
        ac_width = n-v
    else:
        ac_width = v   
        
print(ac_width * ac_length * ac_thick)
    