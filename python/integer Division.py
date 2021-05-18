import math

total_output_count = 0

number_of_element, divisor = map(int,input().split(" "))
list_of_integers = list(map(int,input().split(" ")))
new_list = [math.floor(x/divisor) for x in list_of_integers]

dict_a = {}
for key in new_list:
    dict_a[key] = dict_a.get(key, 0) + 1
for i in dict_a:
    if dict_a[i] > 1:
        total_output_count += sum(range(1,dict_a[i]))

    
print(total_output_count)
