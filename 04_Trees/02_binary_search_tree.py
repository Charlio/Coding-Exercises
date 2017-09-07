class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        self.recursive_insert(self.root, new_val)
        
    def recursive_insert(self, start, new_val):
        if start == None:
            start = Node(new_val)
        elif start.value < new_val:
            self.recursive_insert(start.right, new_val)
        else:
            self.recursive_insert(start.left, new_val)

    def search(self, find_val):
        return self.recursive_search(self.root, find_val)
        
    def recursive_search(self, start, find_val):
        if start == None:
            return False
        elif start.value == find_val:
            return True
        elif start.value < find_val:
            return self.recursive_search(start.right, find_val)
        else:
            return self.recursive_search(start.left, find_val)
            
    
# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print tree.search(4)
# Should be False
print tree.search(6)