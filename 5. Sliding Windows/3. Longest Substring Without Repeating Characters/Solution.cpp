#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> index_map;
        int res = 0;
        int left = 0;
        int right = 0;

        while (right < s.size())
        {
            if (index_map.count(s[right]) != 0 && index_map[s[right]] >= left) left = index_map[s[right]] + 1;
            index_map[s[right]] = right;
            int currLength = right - left + 1;
            if (currLength > res) res = currLength;      
            ++right;
        }

        return res;
    }
};