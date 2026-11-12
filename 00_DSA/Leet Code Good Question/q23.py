# MERGE K SORTED LIST

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists):

        if not lists:
            return None

        return self.mergeRange(lists, 0, len(lists) - 1)

    def mergeRange(self, lists, left, right):

        if left == right:
            return lists[left]

        mid = (left + right) // 2

        l1 = self.mergeRange(lists, left, mid)
        l2 = self.mergeRange(lists, mid + 1, right)

        return self.mergeTwo(l1, l2)

    def mergeTwo(self, l1, l2):

        dummy = ListNode(0)
        current = dummy

        while l1 and l2:

            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next

            current = current.next

        if l1:
            current.next = l1
        else:
            current.next = l2

        return dummy.next