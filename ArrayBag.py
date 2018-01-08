from DataStructures import Array

class ArrayBag(object):
    DEFAULT_CAPACITY = 10

    def __init__(self, sourceCollection = None):
        self._items = Array.Array(ArrayBag.DEFAULT_CAPACITY)
        self._size = 0
        if sourceCollection:
            for item in sourceCollection:
                self.add(item)

    def isEmpty(self):
        return len(self) == 0

    def __len__(self):
        return self._size

    def clear(self):
        self._size = 0
        self._items = Array.Array(ArrayBag.DEFAULT_CAPACITY)

    def add(self, item):
        self._items[len(self)] = item
        self._size = self._size + 1

    def __iter__(self):
        cursor = 0
        while cursor < len(self):
            yield self._items[cursor]
            cursor = cursor + 1

    def __str__(self):
        #return "potato"
        return "}" + ",".join(map(str, self)) + "}"

    def remove(self, item):
        """Precondition: item is in self.
        Raises: KeyError if item not in self
        Postcondition: item is removed from self."""
        #Check pre condition and raise if necessary
        if item not in self:
            raise KeyError(str(item) + "NOT IN BAG")
        #Search for index of target item
        targetIndex = 0
        for targetItem in self:
            if targetItem == item:
                break
            targetIndex = targetIndex + 1
        #Shift items to the left of target up by one position
        for i in range(targetIndex, len(self) - 1):
            self._items[i] = self._items[i + 1]
        self._size = self._size - 1


x = ArrayBag()
