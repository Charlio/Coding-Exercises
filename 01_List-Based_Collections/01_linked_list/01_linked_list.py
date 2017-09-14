"""
Singly Linked List
"""

class Node(object):
    
    def __init__(self, value=None):
        self.value = value
        self.next = None
        
class LinkedList(object):

    def __init__(self, head=None):
        self.head = head
        self.size = 0
        if self.head:
            self.size += 1
        
    def len(self):
        # O(1)
        return self.size
        
    def add_front(self, value):
        # O(1)
        new_node = Node(value)
        new_node.next = self.head.next
        self.head = new_node
        self.size += 1
     
    def append(self, value):
        # O(n)
        cur = self.head
        while cur:
            cur = cur.next
        cur = Node(value)
        self.size += 1
        
    def find(self, value):
        # O(index)
        index = 0
        cur = self.head
        while cur and cur.value != value:
            cur = cur.next
            index += 1
        if cur == None:
            return -1
        else:
            return index
    
    def delete(self, value):
        # O(n)
        if self.head:
            cur = self.head
        while cur.next and cur.next.value != value:
            cur = cur.next
        if cur.next:
            cur.next = cur.next.next
        
    def insert(self, value, index):
        # O(index)
        if index == 0:
            if self.head:
                tmp = self.head.next
                self.head = Node(value)
                self.head.next = tmp
            else:    
                self.head = Node(value)
        
        elif index > 0 and index < self.size:
            cur = self.head
            for i in range(index-1):
                cur = cur.next
            tmp = cur.next
            cur.next = Node(value)
            cur.next.next = tmp
        
    def print_list(self):
        # O(n)
        if self.head:
            print self.head.value,
        cur = self.head.next
        while cur:
            print "->", cur.value,
            cur = cur.next
        print
    

    ############################################
    Advanced Features
    def reverse(self):
        # O(n)
        pass
    
    def find_mth_from_end(self, m):
        # O(n)
        pass
    
    def sort(self):
        # O(n log n)
        pass
        
    def check_cycle(self):
        # O(n)
        pass
        
    
    
        
        