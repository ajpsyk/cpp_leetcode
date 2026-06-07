from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        left = head
        mid = self.find_middle(head)
        right = self.reverse_list(mid)
        reverse_head = right
        while right:
            if left.val != right.val:
                return False

            left = left.next
            right = right.next
        
        self.reverse_list(reverse_head)
        return True
    
    def reverse_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next
        
        return prev
    
    def find_middle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow