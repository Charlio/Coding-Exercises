class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = "aeiouAEIOU"
        front = 0
        back = len(s) - 1
        sls = list(s)
        while front < back:
            while front < back and sls[front] not in vowels:
                front += 1
            while front < back and sls[back] not in vowels:
                back -= 1
            tmp = sls[front]
            sls[front] = sls[back]
            sls[back] = tmp
            front += 1
            back -= 1
        return ''.join(sls)
        