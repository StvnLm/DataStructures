from DataStructures import ArrayBag

class ArraySortedBag(ArrayBag):
    """An array based sorted bag implementation"""

    #Constructor
    def __init__(self, sourceCollection = None):
        """Sets the initial state of self which includes
        the contents of sourceCollection if its present"""
        ArrayBag.__init__(self,sourceCollection)

    def __contains__(self, item):
        "returns if true if item is in bag, false if otherwise"
        left = 0
        right = len(self) - 1
        while left <= right:
            midPoint = (left + right)//2
            if self._items[midPoint] == item:
                return True
            elif self._items[midPoint] > item:
                right = midPoint - 1
            else:
                left = midPoint + 1
        return False

y = ArrayBag()
x = ArraySortedBag()
