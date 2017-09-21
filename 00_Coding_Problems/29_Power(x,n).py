class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if x == 0:
            return None
        if n == 0:
            return 1
        elif n < 0:
            return self.myPow(1/x, -n)
        elif n == 1:
            return x
        else:
            pow = 1
            pow_x = x
            while 2**pow <= n:
                pow_x = pow_x**2
                pow += 1
            pow_x = pow_x*self.myPow(x, n-2**(pow-1))
            return pow_x
            