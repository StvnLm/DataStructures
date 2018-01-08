"""
Jan 1 2018


"""


def insertionSort(lyst):
    for n in range(1, len(lyst)):
        for i in range(n-1, -1, -1):
            if lyst[i] > lyst[i+1]:
                lyst[i], lyst[i+1] = lyst[i+1], lyst[i]
            else:
                break
    return lyst

exampleList = [4, 5, 6, 1, 3, 2, 0]
print(insertionSort(exampleList))
