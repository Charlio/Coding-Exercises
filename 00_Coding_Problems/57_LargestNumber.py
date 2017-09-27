class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        nums_str = map(str, nums)
        nums_str.sort(cmp=lambda x, y: cmp(y+x, x+y))
        return ''.join(nums_str).lstrip('0') or '0'
        
            
        