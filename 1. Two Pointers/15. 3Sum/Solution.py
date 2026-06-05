class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        res = []

        for i in range(len(nums)):
            a = nums[i]

            if i > 0 and a == nums[i - 1]:
                continue
            
            if a > 0:
                break
            
            pairs = self.twoSum(nums, i + 1, -a)

            for pair in pairs:
                res.append([a] + pair)
        
        return res
    
    def twoSum(self, nums: list[int], left: int, target: int):
        right = len(nums) - 1
        pairs = []

        while left < right:
            sum = nums[left] + nums[right]

            if sum == target:
                pairs.append([nums[left], nums[right]])
                left += 1

                while left < right and nums[left] == nums[left - 1]:
                    left += 1


            elif sum < target:
                left += 1
            else:
                right -= 1
            
        return pairs
            