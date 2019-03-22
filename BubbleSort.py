"""
Steven Lam
December 30 2017
Algorithm will compare two items at the beginning of a list. If the
value of a the first item is larger, it will swap them.
"""

def bubbleSort(userList):
    n = len(userList)
    while n > 1:
        i = 1
        while i < n:
            if userList[i] < userList[i - 1]:
                userList[i], userList[i - 1] = userList[i - 1], userList[i]
            i = i + 1
        n = n - 1
    return(userList)

list1 = [0, 4, 3, 2, 1]
print(bubbleSort(list1))


####

array1 = [54,26,93,17,77,31,44,55,20]

def bubbleSort2(arr):
    print(len(arr)-1)
    for x in range(len(arr)-1, 0, -1):

        for y in range(x):
            if arr[y] > arr[y+1]:
                temp = arr[y]
                arr[y], arr[y+1] = arr[y+1], temp

print(bubbleSort2(array1))
