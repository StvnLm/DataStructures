"""
Jan 2 2018

Creating static array and increasing/decreasing the array size

*Doesnt work*
"""
from array import array

capacity = 5
logicalSize = 0
a = array( capacity)

# Increasing the array size
if logicalSize == len(a):                   #If array size is reached...
    tempArray = array(len(a) * 2)           #Creating a new array that has double the memory
    for n in range(0, len(logicalSize)):    #Copy old array into new array
        tempArray[n] = a[n]
    a = tempArray                           #Change old variable to new variable


# Decreasing the size of an array when its logical size is 1/4 of physical size
# and the physical size is atleast twice the default capacity
if logicalSize <= len(a) // 4 and len(a) >= capacity * 2:
    temp = array(len(a) // 2)
    for n in range(logicalSize):
        temp[n] = a[n]
    a = temp


# Inserting items into an array that grows
targetIndex = 3
newItem = 'A'
for i in range(logicalSize, targetIndex, -1):   #Shift items down by one index position
    a[i] = a[i - 1]
a[targetIndex] = newItem
logicalSize = logicalSize + 1

