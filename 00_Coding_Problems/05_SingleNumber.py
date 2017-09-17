class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        for num in nums:
            if num not in d:
                d[num] = 1
            else:
                del d[num]
                
        return d.keys()[0]
        