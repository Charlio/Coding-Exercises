'''
Basic algortihms
'''

'''
binary search
'''
def binary_search(char, array):
    low, high = 0, len(array)-1
    while low <= high:
        mid = (low + high) / 2
        if array[mid] == char:
            return mid
        elif array[mid] < char: # char in the right part
            low = mid + 1
        else: # char in the left part
            high = mid - 1
    return -1


'''
Tree: binary tree traversal: pre-, in-, post- order
Heaps: popout, insert
'''

def binary_tree_preorder(root):
    if root:        
        print root.value
        binary_tree_preorder(root.left)
        binary_tree_preorder(root.right)

def binary_tree_inorder(root):
    if root:        
        binary_tree_inorder(root.left)
        print root.value
        binary_tree_inorder(root.right)

def binary_tree_postorder(root):
    if root:
        binary_tree_postorder(root.left)
        binary_tree_postorder(root.right)
        print root.value

def binary_tree_breadth(root):
    qe = queue()
    qe.push_back(root)
    while !qe.empty():
        cur = qe.front()
        print cur.value
        if cur.left:
            qe.push_back(cur.left)
        if cur.right:
            qe.push_back(cur.right)

        
'''
Map, Hashing
'''


'''
Sort: mergesort, quicksort, bubblesort
'''
def mergesort(array):
    if len(array) == 0 or len(array) == 1:
        return array
    mid = len(array)/2
    left = mergesort(array[:mid])
    right = mergesort(array[mid:])
    merge



'''
graph: depth-first, breadth-first search, shortest path(Dijkstra), minimum spanning tree 
'''



'''
dynamic programming: stock transactions
'''

'''
knapsack, traveling salesman
'''

