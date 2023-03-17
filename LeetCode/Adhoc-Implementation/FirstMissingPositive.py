#https://leetcode.com/problems/first-missing-positive/description/
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [0] + [i if i>0 and i<=len(nums) else 0 for i in nums]
        for ind in range(len(nums)):
            while not (ind==0 or ind==nums[ind] or nums[ind]==0 or nums[nums[ind]]==nums[ind]):
                nums[nums[ind]], nums[ind]  = nums[ind], nums[nums[ind]]
        for (ind, i) in enumerate(nums): 
            if ind!= i:
                return ind
        return len(nums)
            

