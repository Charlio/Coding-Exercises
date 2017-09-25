class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1: return [nums]
        permutations = []
        for i in range(len(nums)):
            tmp = self.permute(nums[:i] + nums[i+1:])
            for perm in tmp:
                permutations.append([nums[i]]+perm)
        return permutations
            
        