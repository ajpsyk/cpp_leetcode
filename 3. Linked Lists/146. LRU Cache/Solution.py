class LRUCache:

    class CacheNode:
        def __init__(self, key: int = 0, val: int = 0):
            self.key = key
            self.val = val
            self.prev = None
            self.next = None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = {}
        self.head = self.CacheNode()
        self.tail = self.CacheNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        

    def get(self, key: int) -> int:
        if key not in self.map: return -1

        node = self.map[key]
        self.remove(node)
        self.addToHead(node)
        return node.val
        

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            node = self.map[key]
            node.val = value
            self.remove(node)
            self.addToHead(node)
            return

        if len(self.map) == self.capacity:
            node_to_remove = self.tail.prev
            self.remove(node_to_remove)
            del self.map[node_to_remove.key]

        new_node = self.CacheNode(key, value)
        self.addToHead(new_node)
        self.map[key] = new_node  
    

    def addToHead(self, node: CacheNode):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node


    def remove(self, node: CacheNode):
        node.next.prev = node.prev
        node.prev.next = node.next
        