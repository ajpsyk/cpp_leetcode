class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        index_map = {}
        left = 0
        right = 0

        while right < len(s):

            if s[right] in index_map and index_map[s[right]] >= left:
                left = index_map[s[right]] + 1
            
            index_map[s[right]] = right
            curr_length = right - left + 1
            res = res if res > curr_length else curr_length

            right += 1
        
        return res
