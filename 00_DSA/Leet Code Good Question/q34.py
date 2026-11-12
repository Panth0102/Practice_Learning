#34. First & Last Position of Element in Sorted Array (Binary Search)

class Solution(object):
    def searchRange(self, nums, target):
        def findBound( isFirst):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = (left + right) 
                if nums[mid] == target:
                    if isFirst:
                        if mid == left or nums[mid - 1] != target:
                            return mid
                        right = mid - 1
                    else:
                        if mid == right or nums[mid + 1] != target:
                            return mid
                        left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1

        first = findBound(True)
        if first == -1:
            return [-1, -1]
        last = findBound(False)
        return [first, last]

#34. First & Last Position of Element in Sorted Array (Linear Search)

#     def searchRange(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         cnt = []
#         for i in range(len(nums)):
#             if nums[i] == target:
#                 cnt.append(i)

#         if(len(cnt) == 0):
#             return [-1, -1]
        
#         return [cnt[0],cnt[-1]]