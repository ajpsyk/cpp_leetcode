#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stack;
        int num = 0;
        int sign = 1;
        int res = 0;

        for (char& c : s)
        {
            if (std::isdigit(c))
            {
                num *= 10;
                num += (c - '0') * sign;
            }
            else if (c == '+' || c == '-')
            {
                sign = (c == '+' ? 1 : -1);
                res += num;
                num = 0;
            }
            else if (c == '(')
            {
                stack.push(res);
                stack.push(sign);

                num = 0;
                sign = 1;
                res = 0;
            }
            else if (c == ')')
            {
                res += num;
                res *= stack.top();
                stack.pop();
                res += stack.top();
                stack.pop();

                num = 0;
                sign = 1;
            }
        }

        return res + num;
    }
};