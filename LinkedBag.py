"""Jan 6 2018
Linked bag implementation"""

from DataStructures import Node

class LinkedBag(object):

    def __init__(self, sourceCollection = None):
        self._items = None
        self._size = None
        if sourceCollection:
            for item in sourceCollection:
                self.add(item)


