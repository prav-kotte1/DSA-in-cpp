class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for i, num in enumerate(nums):
            needed = target - num
            if needed in mp:
                return [mp[needed], i]
            mp[num] = i
        