class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in range(len(nums)):
            if nums[i] != i + 1:
                cur_idx = nums[i] - 1
                while nums[cur_idx] != cur_idx + 1:
                    tmp = nums[cur_idx]
                    nums[cur_idx] = cur_idx + 1
                    nums[i] = tmp
                    cur_idx = nums[i] - 1
        disappeared_nums = []
        for i in range(len(nums)):
            if i+1 != nums[i]:
                disappeared_nums.append(i+1)
        return disappeared_nums