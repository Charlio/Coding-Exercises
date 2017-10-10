class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        matrix = [[None for _ in range(n)] for _ in range(n)]
        cur = (0, 0, 'D')
        val = 1
        for _ in range(n*n):
            matrix[cur[0]][cur[1]] = val
            val += 1
            cur = self.nextPos(cur, n, matrix)
        return matrix
            
    def nextPos(self, cur, n, matrix):
        posX = cur[0]
        posY = cur[1]
        direction = cur[2]
        if direction == 'D':
            if posY < n-1 and matrix[posX][posY+1] == None:
                return (posX, posY+1, 'D')
            else:
                return (posX+1, posY, 'R')
        if direction == 'R':
            if posX < n-1 and matrix[posX+1][posY] == None:
                return (posX+1, posY, 'R')
            else:
                return (posX, posY-1, 'U')
        if direction == 'U':
            if posY > 0 and matrix[posX][posY-1] == None:
                return (posX, posY-1, 'U')
            else:
                return (posX-1, posY, 'L')
        if direction == 'L':
            if posX > 0 and matrix[posX-1][posY] == None:
                return (posX-1, posY, 'L')
            else:
                return (posX, posY+1, 'D')
        