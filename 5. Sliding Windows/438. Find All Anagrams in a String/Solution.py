from typing import List


# this solution relies on the fact that there are only 26 lowercase letters, so we can use a fixed-size array 
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = []
        p_counter = [0] * 26
        s_counter = [0] * 26

        left = 0

        for c in p:
            p_counter[ord(c) - ord('a')] += 1
        
        for right in (range(len(s))):
            s_counter[ord(s[right]) - ord('a')] += 1
            if right - left + 1 == len(p):
                if s_counter == p_counter:
                    res.append(left)
                s_counter[ord(s[left]) - ord('a')] -= 1
                left += 1
        
        return res

# This solution works for any character set, but requires an extra step to remove characters with count 0 from the counter
from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = []
        p_counter = Counter(p)
        s_counter = Counter()

        left = 0
        
        for right in (range(len(s))):
            s_counter[s[right]] += 1
            if right - left + 1 == len(p):
                if s_counter == p_counter:
                    res.append(left)
                s_counter[s[left]] -= 1
                if s_counter[s[left]] == 0:
                    del s_counter[s[left]]
                left += 1
        
        return res