"""
Jan 1 2017
"""

def mergeSort(lyst):
    mergeSort(lyst, 0, len(lyst-1))

def mergeSort2(A, first, last):
    if first < last:
        middle = (first + last)//2
        mergeSort2(A, first, middle)
        
