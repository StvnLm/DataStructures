from DataStructures import ArrayBag

class ArraySortedBag(ArrayBag):
    def __init__(self, sourceCollection = None):
        ArrayBag.__init__(self, sourceCollection)


    def __contains__(self, item):
        left = 0
        right = len(self) - 1
        while left <= right:
            midpoint = (left + right) // 2
            if self._items[midpoint] == item:
                return True
            elif self._items[midpoint] > item:
                right = midpoint - 1
            else:
                left = midpoint + 1
        return False

a = ArraySortedBag()
