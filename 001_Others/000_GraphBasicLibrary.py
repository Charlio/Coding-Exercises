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
        self.node_names = []
        self._node_map = {}
        
    def set_node_names(self, names):
        pass
        
    def insert_node(self, new_node_val):
        pass
    
    def insert_edge(self, new_edge_val, node_from_val, node_to_val):
        pass
    
    def get_edge_list(self):
        pass
        
    def get_edge_list_names(self):
        pass
    
    def get_adjacency_list(self):
        pass
    
    def get_adjacency_list_names(self):
        pass
    
    def get_adjacency_matrix(self):
        pass
        
    def find_max_index(self):
        pass
        
    def find_node(self, node_number):
        pass
        
    def _clear_visited(self):
        pass
        
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
        
    
    
        
        