#include <vector>
#include <cstdlib>

class Solution {
private:
    std::vector<int> prefixSums;
public:
    Solution(std::vector<int>& w) {
        prefixSums.push_back(w[0]);
        for (int i = 1; i < w.size(); ++i)
        {
            prefixSums.push_back(prefixSums.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int target = std::rand() % prefixSums.back() + 1;
        int left = 0;
        int right = prefixSums.size() - 1;

        while (left < right)
        {
            int middle = (right + left) / 2;

            if (prefixSums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        return left;
    }
};