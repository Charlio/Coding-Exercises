class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tails = []
        for num in nums:
            #binary search
            i, j = 0, len(tails)
            while i != j:
                m = (i+j)/2
                if num > tails[m]:
                    i = m + 1
                else:
                    j = m
            if i < len(tails): tails[i] = num
            else: tails.append(num)
        return len(tails)
        