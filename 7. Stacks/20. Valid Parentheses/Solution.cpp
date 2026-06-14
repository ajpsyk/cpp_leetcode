#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char& c : s)
        {
            auto it = map.find(c);
            if (it != map.end())
            {
                if (!stack.empty() && stack.top() == it->second)
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }

        return stack.size() ? false : true;
    }
};