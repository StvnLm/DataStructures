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
