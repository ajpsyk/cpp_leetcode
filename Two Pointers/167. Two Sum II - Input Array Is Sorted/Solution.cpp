#include <vector>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int sum { numbers[left] + numbers[right] };

            if (sum == target)
            {
                ++left;
                ++right;
                return std::vector<int> { left, right };
            }

            else if (sum < target)
            {
                ++left;
            }

            else
            {
                --right;
            } 
        }

        return {};
    }
};
