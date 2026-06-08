#include <string>
#include <unordered_map>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int res = 0;
        std::unordered_map<char, int> freqMap;
        int max_freq = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            ++freqMap[s[right]];
            max_freq = std::max(freqMap[s[right]], max_freq);

            if (right - left + 1 - max_freq > k)
            {
                --freqMap[s[left]];
                ++left;
            }

            res = right - left + 1;
        }

        return res;
    }
};