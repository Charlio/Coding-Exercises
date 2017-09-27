# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root == None:
            return []
        curValue = root.val
        if root.left == None and root.right == None:
            return [str(curValue)]
        
        leftList = self.binaryTreePaths(root.left)
        rightList = self.binaryTreePaths(root.right)
        curList = []
        for st in leftList:
            curList.append(str(curValue)+"->"+st)
        for st in rightList:
            curList.append(str(curValue)+"->"+st)
        return curList
        