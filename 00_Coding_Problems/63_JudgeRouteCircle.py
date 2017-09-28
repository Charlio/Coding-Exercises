class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        move_int = {'R': (1, 0), 'L': (-1, 0), 'U': (0, 1), 'D': (0, -1)}
        pos = [0, 0]
        for move in moves:
            pos[0] += move_int[move][0]
            pos[1] += move_int[move][1]
        return pos == [0, 0]
        