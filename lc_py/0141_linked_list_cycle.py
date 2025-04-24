from typing import Optional

class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not isinstance(head, ListNode):
            return False
        
        seenit = set()
        current_node = head.next
        seenit.add(id(current_node))

        if current_node == None:
            return False

        while current_node.next:
            current_node = current_node.next
            if current_node == None:
                return False
            
            if id(current_node) in seenit:
                return True
            seenit.add(id(current_node))

        return False
            
