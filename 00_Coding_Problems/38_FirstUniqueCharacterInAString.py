class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {}
        for char in s:
            dict[char] = dict.get(char, 0) + 1
        for i in range(len(s)):
            if dict[s[i]] == 1:
                return i
        return -1