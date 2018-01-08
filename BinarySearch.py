"""
Steven Lam
December 30 2017
Finds the midpoint value of a sorted array, and compares the target
value. If it is equal, it returns the target. If the target is less than the
midpoint of the array is split in half, and the left half will be searched.
Vice versa if the target is larger than the midpoint value.
"""
import random

def binarySearch(target, targetArray):
    left = 0
    right = int(len(targetArray))
    while left <= right:
        midpoint = (left + right) // 2
        if target == targetArray[midpoint]:
            return midpoint
        elif target < targetArray[midpoint]:
            right = midpoint -1
        else:
            left = midpoint + 1
    return None

if __name__ == '__main__':
    exampleArray = [0, 1, 2, 4, 8, 9, 10, 11, 12, 13, 14, 15]
    randomInt = random.randint(0,15)
    print('Performing binary search for: ',
          randomInt,
          ', Index value: ',
          binarySearch(randomInt, exampleArray)
          )
