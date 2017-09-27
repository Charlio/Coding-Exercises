class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(A)
        p = len(A[0])
        n = len(B[0])
        C = [[0 for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for k in range(p):
                if A[i][k]:
                    for j in range(n):
                        if B[k][j]:
                            C[i][j] += A[i][k]*B[k][j]
        return C