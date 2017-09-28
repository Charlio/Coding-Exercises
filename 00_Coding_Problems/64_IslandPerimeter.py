class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        land_count = 0
        neighbor_count = 0
        
        rows = len(grid)
        cols =len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    land_count += 1
                    neighbor_count += self.count_neighbors(i, j, grid)
        return land_count * 4 - neighbor_count
    
    def count_neighbors(self, i, j, grid):
        neighbor_count = 0
        if i-1 >= 0 and grid[i-1][j] == 1:
            neighbor_count += 1
        if j-1>=0 and grid[i][j-1] == 1:
            neighbor_count += 1
        if i+1 < len(grid) and grid[i+1][j] == 1:
            neighbor_count += 1
        if j+1 < len(grid[0]) and grid[i][j+1] == 1:
            neighbor_count += 1
        return neighbor_count
        