from collections import Counter

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq_map = Counter()
        max_freq = 0
        count = 0
        left = 0
        right = 0

        for right in range(len(s)):
            freq_map[s[right]] += 1
            max_freq = max_freq if max_freq > freq_map[s[right]] else freq_map[s[right]]

            if right - left + 1 - max_freq > k:
                freq_map[s[left]] -= 1
                left += 1

            count = right - left + 1 

        return count