class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        uniques = set()
        for num in nums:
            if num in uniques: return True
            else:
                uniques.add(num)
        return False