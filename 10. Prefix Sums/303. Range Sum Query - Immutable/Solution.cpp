#include <vector>

class NumArray {
private:
    std::vector<int> prefixSums;
public:
    NumArray(std::vector<int>& nums) {
        for (const int& num : nums)
        {
            if (prefixSums.empty())
            {
                prefixSums.push_back(num);
            }
            else
            {
                prefixSums.push_back(prefixSums.back() + num);
            }
           
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
        {
            return prefixSums[right];
        }
        return prefixSums[right] - prefixSums[left - 1];
    }
};