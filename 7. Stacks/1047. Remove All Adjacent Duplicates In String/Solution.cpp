#include <string>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::string res;

        for (char& c : s)
        {
            (res.empty() || res.back() != c) ? res.push_back(c) : res.pop_back();
        }

        return res;
    }
};