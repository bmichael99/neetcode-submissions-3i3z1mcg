from typing import List

def read_integers() -> List[int]:
    inp = input()
    my_list = inp.split(",")
    int_list = []
    for val in my_list:
        int_list.append(int(val))
    return int_list

# do not modify the code below
print(read_integers())
print(read_integers())
print(read_integers())
