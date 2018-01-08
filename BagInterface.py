"""
January 4 2018
Steven Lam

Creating psuedo-interfaces
"""

class BagInterface(object):
    """Interface for all bag types; note: an interface never discloses how am operation
    performs its task. That's up to the implementors"""

    # Constructor
    def __init__(self, sourceCollection = None):
        """sets the initial state of self, which includes the
        contents of sourceCollection if its present"""
        pass

    # Accessor Methods
    def isEmpty(self):
        """Returns True is len(self) == 0"""
        return True

    def __len__(self):
        """Returns the number of items in self"""
        return 0

    def __str__(self):
        """Returns the string representation of self"""
        return ""

    def __iter__(self):
        """Supports iteration over a view of self"""
        return None

    def __add__(self):
        """Returns a new bag containing the contents of self and other"""
        return None

    def __eq__(self, other):
        """Returns True if self equals other"""
        return False

    # Mutator methods

    def clear(self):
        """Makes self become empty"""
        pass

    def add(self, item):
        """Adds item to self"""
        pass

    def remove(self, item):
        """Precondition: item is in self.
        Raises: KeyError if item is not in self.
        Postcondition: item is removed from self."""
        pass

