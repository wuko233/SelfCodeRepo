from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow

        # index = 0
        # isEnd = False
        # cur = head
        # while not isEnd:
        #     if cur.next:
        #         cur = cur.next
        #     else:
        #         isEnd = True
        #     index += 1
        # midIndex = index // 2 + 1
        # idx = 1
        # cur = head
        # while True:
        #     if idx == midIndex:
        #         break
        #     cur = cur.next
        #     idx += 1
        # return cur
