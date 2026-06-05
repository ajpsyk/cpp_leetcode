from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums: return 0

        longest_chain = 0
        num_set = set(nums)

        for num in num_set:

            if num - 1 not in num_set:
                curr_num = num
                curr_chain = 1

                while curr_num + 1 in num_set:
                    curr_num += 1
                    curr_chain += 1
                
                longest_chain = curr_chain if curr_chain > longest_chain else longest_chain
        
        return longest_chain