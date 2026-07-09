from typing import List


def find_max_in_each_list(nested_arr: List[List[int]]) -> List[int]:
    max_vals = []
    for i, sublist in enumerate(nested_arr):
        curr_max = nested_arr[i][0]
        for j, val in enumerate(nested_arr[i]):
                curr_max = max(curr_max,nested_arr[i][j])
        max_vals.append(curr_max)
    return max_vals


# do not modify below this line
print(find_max_in_each_list([[1, 2], [3, 4, 2]]))
print(find_max_in_each_list([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
print(find_max_in_each_list([[5, 6, 2, 8], [9], [9, 10], [11, 10, 11]]))
