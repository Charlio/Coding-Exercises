class Node(object):
    def __init__(self, value):
        self.value = value
        self.edges = []
        self.visited = False
        
class Edge(object):
    def __init__(self, value, node_from, node_to):
        self.value = value
        self.node_from = node_from
        self.node_to = node_to
        
class Graph(object):
    def __init__(self, nodes=None, edges=None):
        self.nodes = nodes or []
        self.edges = edges or []
        self.node_names = [] # node names indexed by 0-based node numbers
        self._node_map = {} # maps from node value to Node object
        
    def set_node_names(self, names):
        '''
        nth name in names corresponds to node number n (0-based)
        '''
        self.node_names = list(names)
        
    def insert_node(self, new_node_val):
        new_node = Node(new_node_val)
        self.nodes.append(new_node)
        self._node_map[new_node_val] = new_node
        return new_node
    
    def insert_edge(self, new_edge_val, node_from_val, node_to_val):
        '''
        insert new edge and create new nodes if necessary
        '''
        if node_from_val not in self._node_map:
            self.insert_node(node_from_val)
        if node_to_val not in self._node_map:
            self.insert_node(node_to_val)
        node_from = self._node_map[node_from_val]
        node_to = self._node_map[node_to_val]
        new_edge = Edge(new_edge_val, node_from, node_to)
        node_from.edges.append(new_edge)
        node_to.edges.append(new_edge)
        self.edges.append(new_edge)
            
    def get_edge_list(self):
        '''
        return a list of triples: (edge_val, node_from_val, node_to_val)
        '''
        return [(edge.value, edge.node_from.value, edge.node_to.value) for edge in self.edges]
        
    def get_edge_list_names(self):
        '''
        return a list of triples: (edge_val, node_from name, node_to name)
        '''
        return [(edge.value, self.node_names[edge.node_from.value], 
                self.node_names[edge.node_to.value]) for edge in self.edges]
    
    def get_adjacency_list(self):
        '''
        return a list of lists, the outer list is indexed by node values of from nodes
        each section in the list is a list of tuples (to node value, edge value)
        '''
        max_idx = self.find_max_index()
        adj_list = [[] for _ in range(max_idx+1)]
        for e in self.edges:
            from_val, to_val = e.node_from.value, e.node_to.value
            adj_list[from_val].append((to_val, e.value))
        return [a or None for a in adj_list] # replace [] with None
    
    def get_adjacency_list_names(self):
        '''
        return a list of lists, the outer list is indexed by node names of from nodes
        each section in the list is a list of tuples (to node names, edge value)
        '''        
        max_idx = self.find_max_index()
        adj_list = [[] for _ in range(max_idx+1)]
        for e in self.edges:
            from_val, to_val = e.node_from.value, e.node_to.value
            adj_list[from_val].append((self.node_names[to_val], e.value))
        return [a or None for a in adj_list] # replace [] with None 
 
    def get_adjacency_matrix(self):
        '''
        return a matrix or a 2D list. Row numbers represent from node values, column numbers
        represent to node values. Each entry represent edge values, 0 if no edge.
        '''
        max_idx = self.find_max_index()
        adj_mat = [[0]*(max_idx+1) for _ in range(max_idx+1)]
        for e in self.edges:
            from_val, to_val = e.node_from.value, e.node_to.value
            adj_mat[from_val][to_val] = e.value
        return adj_mat
        
    def find_max_index(self):
        '''
        find the maximum found node values or the length of node names if set with set_node_names()
        '''
        if len(self.node_names) > 0:
            return len(self.node_names)
        max_idx = -1
        if len(self.nodes) > 0:
            for node in self.nodes:
                if node.value > max_idx:
                    max_idx = node.value
        return max_idx
        
    def find_node(self, node_number):
        '''
        return Node object with node_number or None
        '''
        return self._node_map.get(node_number)
        
    def _clear_visited(self):
        for node in self.nodes:
            node.visited = False
        
    def dfs_helper_recursive(self, start_node):
        '''
        Inplement Depth-First Search of a graph with recursion iterating through each node's edges
        OUTPUTS: a list of node numbers corresponding to the traversed nodes
        in a Depth-First Search
        ARGUMENTS: the start node (Node object)
        MODIFIES: set self.visited to True in each Node object 
        RETURN: a list of node values (int)
        '''
        ret_list = [start_node.value]
        start_node.visited = True
        for edge in start_node.edges:
            if edge.node_to.visited == False:
                ret_list += self.dfs_helper(edge.node_to)
        return ret_list
        
    def dfs_helper_iterative(self, start_node):
        '''
        Inplement Depth-First Search of a graph with iteration through each node's edges
        OUTPUTS: a list of node numbers corresponding to the traversed nodes
        in a Depth-First Search
        ARGUMENTS: the start node (Node object)
        MODIFIES: set self.visited to True in each Node object 
        RETURN: a list of node values (int)
        '''    
        self._clear_visited()
        ret_list = []
        stack = [start_node]
        start_node.visited = True
        while stack:
            curr_node = stack.pop()
            ret_list.append(curr_node.value)
            for i in range(len(curr_node.edges)-1, -1, -1):
                if curr_node.edges[i].node_from == curr_node and curr_node.edges[i].node_to.visited == False:
                    stack.append(curr_node.edges[i].node_to)
                    curr_node.edges[i].node_to.visited = True
        return ret_list
        
        
    def dfs(self, start_node_num):
        '''
        OUTPUTS: a list of node numbers corresponding to the traversed nodes
        in a Depth-First Search
        ARGUMENTS: the start node number (int)
        MODIFIES: set self.visited to True in each Node object 
        RETURN: a list of node values (int)
        '''
        self._clear_visited()
        start_node = self.find_node(start_node_num)
        return self.dfs_helper_iterative(start_node)
        
        
    def dfs_names(self, start_node_num):
        '''
        return results from dfs with node numbers converted to node names
        '''
        return [self.node_names[node_num] for node_num in self.dfs(start_node_num)]
        
    def bfs(self, start_node_num):
        '''
        Inplement Breadth-First Search of a graph with iteration through each node's edges
        OUTPUTS: a list of node numbers corresponding to the traversed nodes
        in a Breadth-First Search
        ARGUMENTS: the start node number (int)
        MODIFIES: set self.visited to True in each Node object 
        RETURN: a list of node values (int)
        '''
        start_node = self.find_node(start_node_num)
        self._clear_visited()
        ret_list = []
        queue = [start_node]
        start_node.visited = True
        while queue:
            curr_node = queue.pop(0)
            ret_list.append(curr_node.value)
            for edge in curr_node.edges:
                if edge.node_from == curr_node and edge.node_to.visited == False:
                    queue.append(edge.node_to)
                    edge.node_to.visited = True
        return ret_list
        
        
    def bfs_names(self, start_node_num):
        '''
        return results from bfs with node numbers converted to node names
        '''
        return [self.node_names[node_num] for node_num in self.bfs(start_node_num)]
        
        
        
    def get_edge_cost(self, node_from_val, node_to_val):
        node_from = self.find_node(node_from_val)
        for edge in node_from.edges:
            if edge.node_to.value == node_to_val:
                return edge.value
        return None
        
    def get_node_val_from_name(self, node_name):
        for i in range(len(self.node_names)):
            if self.node_names[i] == node_name:
                return i
        return -1
        
    def present_costs(self, node_list, asNum = True):
        '''
        given a list of nodes, add edge cost between consecutive nodes, 
        nodes can be given as node numbers or node names
        '''
        ret_list = []
        if asNum == False:
            for i in range(len(node_list)):
                node_list[i] = self.get_node_val_from_name(node_list[i])
        ret_list_cost = [node_list[0]]
        for i in range(1, len(node_list)):
            ret_list_cost.append(self.get_edge_cost(ret_list[-1], node_list[i])) # search for the edge cost
            ret_list_cost.append(node_list[i])
        return ret_list_cost 
    
     
    def mcs(self, start_node_num, end_node_num, show_costs = True):
        '''
        Implement minimum cost search from a given node to another given node based on edge costs.
        Implementation uses Dijkstra's algorithm
        OUTPUTS: a list of node numbers corresponding to the traversed nodes
        in a minimum cost search. If show_costs sets to True, then also present edge costs between nodes
        ARGUMENTS: the start and end node numbers (int)
        MODIFIES: 
        RETURN: a list of node values (int), consecutive nodes are separated by the edge cost (int) between them
        '''
        max_idx = self.find_max_index()
        prev = [None]*(max_idx + 1)
        v_set = [(node.value, float('inf')) for node in self.nodes]
        self._clear_visited()
        while v_set:
            curr_node = v_set.find(min(dist))
            v_set.remove(curr_node)
            
        pass
        
    def mcs_names(self, start_node_num, end_node_num, show_costs = True):
        '''
        return results from mcs with node numbers converted to node names
        '''
        ret_list = self.mcs(start_node_num, end_node_num, False)
        ret_list_names = [self.node_names[node_num] for node_num in ret_list]
        return self.present_costs(ret_list_names, False)
        



     
# TESTS




'''
# test graph representation
graph = Graph()
graph.insert_edge(100, 1, 2)
graph.insert_edge(101, 1, 3)
graph.insert_edge(102, 1, 4)
graph.insert_edge(103, 3, 4)
# Should be [(100, 1, 2), (101, 1, 3), (102, 1, 4), (103, 3, 4)]
print graph.get_edge_list()
# Should be [None, [(2, 100), (3, 101), (4, 102)], None, [(4, 103)], None]
print graph.get_adjacency_list()
# Should be [[0, 0, 0, 0, 0], [0, 0, 100, 101, 102], [0, 0, 0, 0, 0], [0, 0, 0, 0, 103], [0, 0, 0, 0, 0]]
print graph.get_adjacency_matrix()
'''




# test dfs and bfs
graph = Graph()

# You do not need to change anything below this line.
# You only need to implement Graph.dfs_helper and Graph.bfs

graph.set_node_names(('Mountain View',   # 0
                      'San Francisco',   # 1
                      'London',          # 2
                      'Shanghai',        # 3
                      'Berlin',          # 4
                      'Sao Paolo',       # 5
                      'Bangalore'))      # 6 

graph.insert_edge(51, 0, 1)     # MV <-> SF
graph.insert_edge(51, 1, 0)     # SF <-> MV
graph.insert_edge(9950, 0, 3)   # MV <-> Shanghai
graph.insert_edge(9950, 3, 0)   # Shanghai <-> MV
graph.insert_edge(10375, 0, 5)  # MV <-> Sao Paolo
graph.insert_edge(10375, 5, 0)  # Sao Paolo <-> MV
graph.insert_edge(9900, 1, 3)   # SF <-> Shanghai
graph.insert_edge(9900, 3, 1)   # Shanghai <-> SF
graph.insert_edge(9130, 1, 4)   # SF <-> Berlin
graph.insert_edge(9130, 4, 1)   # Berlin <-> SF
graph.insert_edge(9217, 2, 3)   # London <-> Shanghai
graph.insert_edge(9217, 3, 2)   # Shanghai <-> London
graph.insert_edge(932, 2, 4)    # London <-> Berlin
graph.insert_edge(932, 4, 2)    # Berlin <-> London
graph.insert_edge(9471, 2, 5)   # London <-> Sao Paolo
graph.insert_edge(9471, 5, 2)   # Sao Paolo <-> London
# (6) 'Bangalore' is intentionally disconnected (no edges)
# for this problem and should produce None in the
# Adjacency List, etc.

import pprint
pp = pprint.PrettyPrinter(indent=2)

print "Edge List"
pp.pprint(graph.get_edge_list_names())

print "\nAdjacency List"
pp.pprint(graph.get_adjacency_list_names())

print "\nAdjacency Matrix"
pp.pprint(graph.get_adjacency_matrix())

print "\nDepth First Search"
pp.pprint(graph.dfs_names(2))

# Should print:
# Depth First Search
# ['London', 'Shanghai', 'Mountain View', 'San Francisco', 'Berlin', 'Sao Paolo']

print "\nBreadth First Search"
pp.pprint(graph.bfs_names(2))
# test error reporting
# pp.pprint(['Sao Paolo', 'Mountain View', 'San Francisco', 'London', 'Shanghai', 'Berlin'])

# Should print:
# Breadth First Search
# ['London', 'Shanghai', 'Berlin', 'Sao Paolo', 'Mountain View', 'San Francisco']
    
        
        