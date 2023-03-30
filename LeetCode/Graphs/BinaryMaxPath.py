# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
class Solution(object):
    def dfs(self, cur):
        if cur is None: 
            return (-10000, -10000)
        a = self.dfs(cur.left)
        b = self.dfs(cur.right)
        r0 = max([a[0], b[0], 0]) + cur.val
        r1 = max([a[1], b[1], a[0] + b[0] + cur.val, r0])
        return (r0, r1)
        
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root)[1]
