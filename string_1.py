user_input = input()


char_list = list(user_input)
another_list = []

lenth = len(char_list)


while lenth > 0:
   
    if len(char_list) > 0:
        another_list.append(char_list.pop(0))  
    if len(char_list) > 0:
        another_list.append(char_list.pop(0))  
    
   
    if len(char_list) > 0:
        another_list.append(char_list.pop(0).upper()) 

    lenth = len(char_list)


print(''.join(another_list))
