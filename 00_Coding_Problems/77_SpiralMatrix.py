class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if matrix == []:
            return []
        m = len(matrix)
        n = len(matrix[0])
        N = m * n
        cur_pos_dir = (0, 0, 'D')
        spiral = [matrix[cur_pos_dir[0]][cur_pos_dir[1]]]
        matrix[cur_pos_dir[0]][cur_pos_dir[1]] = None
        for _ in range(N-1):
            cur_pos_dir = self.nextEle(cur_pos_dir, m, n, matrix)
            spiral.append(matrix[cur_pos_dir[0]][cur_pos_dir[1]])
        return spiral
    
    def nextEle(self, cur_pos_dir, m, n, matrix):
        posX = cur_pos_dir[0]
        posY = cur_pos_dir[1]
        direction = cur_pos_dir[2]
        matrix[posX][posY] = None

        if direction == 'R':
            if posX < m-1 and matrix[posX+1][posY] != None:
                return (posX+1, posY, 'R')
            else:
                return (posX, posY-1, 'U')
        if direction == 'D':
            if posY < n-1 and matrix[posX][posY+1] != None:
                return (posX, posY+1, 'D')
            else:
                return (posX+1, posY, 'R')
        if direction == 'L':
            if posX > 0 and matrix[posX-1][posY] != None:
                return (posX-1, posY, 'L')
            else:
                return (posX, posY+1, 'D')
        if direction == 'U':
            if posY > 0 and matrix[posX][posY-1] != None:
                return (posX, posY-1, 'U')
            else:
                return (posX-1, posY, 'L')