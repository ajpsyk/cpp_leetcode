#include <vector>
#include <string>

// This solution relies on the fact that there are only 26 lowercase letters, so we can use a fixed-size array 
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> pCounter(26, 0);
        std::vector<int> sCounter(26, 0);
        std::vector<int> res;

        for (char c : p)
        {
            ++pCounter[c - 'a']; 
        }

        int left = 0;
        int right = 0;

        while (right < s.size())
        {
            ++sCounter[s[right] - 'a'];

            if (right - left + 1 == p.size())
            {
                if (pCounter == sCounter) res.push_back(left);
                --sCounter[s[left] - 'a'];
                ++left;
            }

            ++right;
        }

        return res;
    }
};