class MultiLevelListNode:
    def __init__(self, val=None, next=None, child=None):
        self.val = val
        self.next = next
        self.child = child


def flatten_multi_level_list(head: MultiLevelListNode) -> MultiLevelListNode:
    if not head:
        return None

    tail = head
    while tail.next:
        tail = tail.next

    
    curr = head
    while curr:
        if curr.child:
            tail.next = curr.child
            curr.child = None

            while tail.next:
                tail = tail.next

        curr = curr.next
    
    return head