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
            insert_node(node_from_val)
        if node_to_val not in self._node_map:
            insert_node(node_to_val)
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
        adj_list = [[] for _ in range(max_idx)]
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
        adj_list = [[] for _ in range(max_idx)]
        for e in self.edges:
            from_val, to_val = e.node_from.value, e.node_to.value
            adj_list[from_val].append((self._node_map[to_val], e.value))
        return [a or None for a in adj_list] # replace [] with None 
 
    def get_adjacency_matrix(self):
        '''
        return a matrix or a 2D list. Row numbers represent from node values, column numbers
        represent to node values. Each entry represent edge values, 0 if no edge.
        '''
        max_idx = self.find_max_index()
        adj_mat = [[0]*max_idx for _ in range(max_idx)]
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
        
    def dfs_helper(self, start_node):
        pass
        
    def dfs(self, start_node_num):
        pass
        
    def dfs_names(self, start_node_num):
        pass
        
    def bfs(self, start_node_num):
        pass
        
    def bfs_names(self, start_node_num):
        pass
        
# TESTS
graph = Graph()

    
        
        