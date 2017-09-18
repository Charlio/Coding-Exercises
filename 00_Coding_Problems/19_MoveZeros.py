class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        write = 0
        for read in range(len(nums)):
            if nums[read] != 0:
                if write != read:
                    nums[write] = nums[read]
                    nums[read] = 0
                write += 1
                