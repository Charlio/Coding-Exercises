class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x_list = list(str(x))
        if x_list[0] == '-':
            x_reversed = ''.join([x_list[0]] + x_list[1:][::-1])
            new_x = int(x_reversed)
        else: 
            x_reversed = ''.join(x_list[::-1])
            new_x = int(x_reversed)
        if new_x >= 2**31-1 or new_x < -2**31:
            return 0
        else:
            return new_x
