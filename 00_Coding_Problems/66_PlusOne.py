class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        add_one = 1
        for i in range(n):
            tmp = digits[n-1-i] + add_one
            digits[n-1-i] = tmp % 10
            add_one = tmp / 10
        if add_one == 1:
            digits = [1] + digits
        return digits
        