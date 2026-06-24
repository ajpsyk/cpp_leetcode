from typing import List, Optional
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []
        i = 0
        for head in lists:
            if head:
                heapq.heappush(min_heap, (head.val, i, head))
                i += 1
        
        dummy = ListNode()
        curr = dummy

        while min_heap:
            _, index, node = heapq.heappop(min_heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(min_heap, (node.next.val, index, node.next))
        
        return dummy.next
    