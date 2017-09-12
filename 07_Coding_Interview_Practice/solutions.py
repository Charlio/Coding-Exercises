"""
solutions to the technical interview practice of Machine Learning
Engineer Nanodegree at Udacity
"""


def question1(s, t):
    """
    Given two strings s and t, determine whether some anagram of t is a substring of s. 
    For example: if s = "udacity" and t = "ad", then the function returns True. 
    Inputs: two strings s, t
    Output: boolean
    """
    #TODO
    if s == "" or t == "": return False
    from itertools import permutations
    anagrams = [''.join(p) for p in permutations(t)]
    for anagram in anagrams:
        if s.find(anagram) != -1:
            return True
    return False
    
"""
test cases for question 1
"""    
print("test cases for question 1: ")
print(question1("", "question"))
# False
print(question1("question", ""))
# False
print(question1("artificial", "lia"))
# True
print(question1("intelligence", "get"))
# False
print("")
    
    
    
    
    
    
    
def question2(a):
    """
    Given a string a, find the longest palindromic substring contained in a. 
    Input: a string a
    Output: a string
    """
    #TODO
    if a == "": return ""
    longest_palindrome = ""
    for i in range(2*len(a)-1):
        t = longest_palindrome_centered(i, a)
        if len(t) > len(longest_palindrome):
            longest_palindrome = t
    return longest_palindrome
    
def longest_palindrome_centered(i, s):
    """
    Given a string s, and an index i, return the longest palindrome substring in s centered at i
    when i is even, it corresponds to index i/2 of s
    when i is odd, it corresponds to the empty center between indices (i-1)/2 and (i+1)/2 of s
    Inputs: a non-negative integer i, a string s
    Output: a string
    """
    longest_palindrome = ""
    n = len(s)
    if i % 2 == 0:
        longest_palindrome = s[i/2]
        left, right = i/2 - 1, i/2 + 1
    else:
        left, right = (i-1)/2, (i+1)/2
    while left >= 0 and right < n and s[left] == s[right]:
        longest_palindrome = s[left:right+1]
        left -= 1
        right += 1
    return longest_palindrome
        
"""
test cases for question 2
"""    
print("test cases for question 2: ")
print(question2(""))
# ""
print(question2("abac"))
# "aba"
print(question2("cdefaabbaaaf"))
# "aabbaa"
print(question2("etgcccdefedcccfshsragbsfhsd"))
# "cccdefedccc"
print("")
    
    

   


   
def question3(G):
    """
    Given an undirected graph G, find the minimum spanning tree within G.
    Input: an edge-weighted undirected graph G represented as an adjacency list
    Output: an adjacency list 
    """
    #TODO
    # Kruskal's algorithm
    mst = {}
    for v in G.keys():
        mst[v] = []
    tree_sets = [set(v) for v in G.keys()]
    sorted_edges = get_sorted_edges(G)
    for edge in sorted_edges:
        u, v = edge[0], edge[1]
        u_set_ind = find_set(u, tree_sets)
        v_set_ind = find_set(v, tree_sets)
        if tree_sets[u_set_ind] != tree_sets[v_set_ind]:
            add_edge(edge, mst)
            merge(u_set_ind, v_set_ind, tree_sets)
    for v in mst:
        mst[v].sort()
    return mst
    
def get_sorted_edges(G):
    """
    Given a graph G, return a list of edges sorted in nondecreasing order with respect to weights
    Iuput: a weighted graph G represented as an adjacent list (a dictionary)
    Output: a list of tuples representing weighted edges, each weighted edge is represented as a tuple (A, B, w)
    """
    edges = []
    for v in G.keys():
        for edge in G[v]:
            if (edge[0], v, edge[1]) not in edges:
                edges.append((v, edge[0], edge[1]))
    return sorted(edges, key=lambda item: item[2])
    
def find_set(v, sets):
    """
    given an element v, check whether it is in a set in sets
    Inputs: an element v, a list of sets
    Output: the index of the set containing v, otherwise -1
    """
    for set_ind in range(len(sets)):
        if v in sets[set_ind]:
            return set_ind
    return -1

def add_edge(edge, mst):
    """
    Given an edge in form of a tuple (v1, v2, weight), add it into the minimum spanning tree mst
    Inputs: a tuple edge, an adjacency list (dictionary) representing the minimum spanning tree
    Output: no output
    """
    v1, v2, weight = edge
    mst[v1] = mst[v1] + [(v2, weight)]
    mst[v2] = mst[v2] + [(v1, weight)]
    
def merge(set1_ind, set2_ind, sets):
    """
    merge set1 and set2 in sets: in sets, add the union of set1 and set2, delete set1 and set2
    Inputs: two sets indices set1_ind, set2_ind and a list of sets
    Output: no output
    """
    set1 = sets[set1_ind]
    set2 = sets[set2_ind]
    sets.remove(set1)
    sets.remove(set2)    
    sets.append(set1.union(set2))

"""
test cases for question 3
"""    

print("test cases for question 3: ")
print(question3({}))
# {}

# graph from wikipedia: Kruskal's algorithm
print(question3({'A': [('B', 7), ('D', 5)],
                 'B': [('A', 7), ('C', 8), ('D', 9), ('E', 7)],
                 'C': [('B', 8), ('E', 5)],
                 'D': [('A', 5), ('B', 9), ('E', 15), ('F', 6)],
                 'E': [('B', 7), ('C', 5), ('G', 9), ('F', 8)],
                 'F': [('D', 6), ('E', 8), ('G', 11)],
                 'G': [('E', 9), ('F', 11)]}))
#{'A': [('B', 7), ('D', 5)], 
# 'C': [('E', 5)], 
# 'B': [('A', 7), ('E', 7)], 
# 'E': [('B', 7), ('C', 5), ('G', 9)], 
# 'D': [('A', 5), ('F', 6)], 
# 'G': [('E', 9)], 
# 'F': [('D', 6)]}

# G from "Introduction to Algorithms" by CLRS, page 632
G = {'A':[('B', 4), ('H', 8)],
     'B':[('A', 4), ('C', 8), ('H', 11)],
     'C':[('B', 8), ('D', 7), ('F', 4), ('I', 2)],
     'D':[('C', 7), ('E', 9), ('F', 14)],
     'E':[('D', 9), ('F', 10)],
     'F':[('C', 4), ('D', 14), ('E', 10), ('G', 2)],
     'G':[('F', 2), ('H', 1), ('I', 6)],
     'H':[('A', 8), ('B', 11), ('G', 1), ('I', 7)],
     'I':[('C', 2), ('G', 6), ('H', 7)]}
print(question3(G))    
#{'A': [('B', 4), ('H', 8)], 
# 'C': [('D', 7), ('F', 4), ('I', 2)], 
# 'B': [('A', 4)], 
# 'E': [('D', 9)], 
# 'D': [('C', 7), ('E', 9)], 
# 'G': [('F', 2), ('H', 1)], 
# 'F': [('C', 4), ('G', 2)], 
# 'I': [('C', 2)], 
# 'H': [('A', 8), ('G', 1)]}
print("")
    
    
    
    
  


  
def question4(T, r, n1, n2):
    """
    Find the least common ancestor between two nodes on a binary search tree.
    Inputs: a binary search tree T represented as a matrix, where the index of 
    the list is equal to the integer stored in that node and a 1 represents a child node;
    r is a non-negative integer representing the root, and n1 and n2 are non-negative 
    integers representing the two nodes in no particular order.
    Output: a non-negative integer representing the least common ancestor in the tree matrix
    """
    #TODO
    anc = r
    while (anc - n1)*(anc - n2) > 0:
        anc = [child for child in range(len(T)) if T[anc][child] == 1][n1>anc]
    return anc
    
"""
test cases for question 4
"""  
print("test cases for question 4: ")
print(question4([[0, 1, 0, 0, 0],
                 [0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0],
                 [1, 0, 0, 0, 1],
                 [0, 0, 0, 0, 0]],
                3,
                1,
                4
               )
     )
# 3
print(question4([[0,0,0,0,0,0,0,0,0,0],
                 [1,0,0,0,0,0,0,0,1,0],
                 [1,0,0,0,1,0,0,0,0,0],
                 [0,0,0,0,0,0,0,0,0,0],
                 [0,0,0,1,0,1,0,0,0,0],
                 [0,0,0,0,0,0,0,0,0,0],
                 [0,0,1,0,0,0,0,0,1,0],
                 [0,0,0,0,0,0,0,0,0,0],
                 [0,0,0,0,0,0,0,1,0,1],
                 [0,0,0,0,0,0,0,0,0,0]], 
                6,
                3,
                9
               )
     )
# 6
print(question4([[0,0,0,0,0,0,0,0,0,0],
                 [1,0,0,0,0,0,0,0,1,0],
                 [1,0,0,0,1,0,0,0,0,0],
                 [0,0,0,0,0,0,0,0,0,0],
                 [0,0,0,1,0,1,0,0,0,0],
                 [0,0,0,0,0,0,0,0,0,0],
                 [0,0,1,0,0,0,0,0,1,0],
                 [0,0,0,0,0,0,0,0,0,0],
                 [0,0,0,0,0,0,0,1,0,1],
                 [0,0,0,0,0,0,0,0,0,0]], 
                6,
                2,
                4
               )
     )
# 2
print("")
   
  
  
  
  
  
  
  
  
  
class Node(object):
  def __init__(self, data):
    self.data = data
    self.next = None   
     
def question5(ll, m):
    """
    Find the element in a singly linked list that's m elements from the end.
    Inputs: the first node of a linked list ll, mth number from the end m
    Output: value of the node at that position
    """
    #TODO
    slow = ll
    fast = ll
    for i in range(m):
        if fast == None: return "None"
        else: fast = fast.next
    while fast != None:
        slow = slow.next
        fast = fast.next
    return slow.data
    
"""
test cases for question 5
"""
ll = Node(1)
cur = ll
for i in range(2, 6):
    cur.next = Node(i)
    cur = cur.next

  
print("test cases for question 5: ")
print(question5(None, 3))
# None
print(question5(ll, 2))
# 4
print(question5(ll, 6))
# None
print(question5(ll, 1))
# 5
print(question5(ll, 5))
# 1 



