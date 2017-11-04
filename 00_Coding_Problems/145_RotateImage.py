class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n == 0 or n ==1:
            return
        # transpose
        
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # horizontal flip
        
        i, j = 0, n-1
        while i < j :
            for k in range(n):
                matrix[k][i], matrix[k][j] = matrix[k][j], matrix[k][i]
            i += 1
            j -= 1