from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.post_order(root) != -1
    
    def post_order(self, root):
        if not root:
            return 0
        
        left = self.recurse(root.left)
        right = self.recurse(root.right)

        if abs(left - right) > 1:
            return -1

        if left == -1 or right == -1:
            return -1
        
        return max(left, right) + 1