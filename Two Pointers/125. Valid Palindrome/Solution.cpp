#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                ++left;
            }

            while (left < right && !isalnum(s[right]))
            {
                --right;
            }

            char a = tolower(s[left]);
            char b = tolower(s[right]);

            if (a != b)
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};