#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfixProduct = 1;
        
        for (int j = nums.size() - 1; j > -1; --j)
        {
            res[j] *= postfixProduct;
            postfixProduct *= nums[j];
        }

        return res;
    }
};