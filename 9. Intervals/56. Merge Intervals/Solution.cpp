#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> res;

        for (const std::vector<int>& interval : intervals)
        {
            if (!res.empty() && interval[0] <= res.back()[1])
            {
                res.back()[1] = std::max(res.back()[1], interval[1]);
            }
            else
            {
                res.push_back(interval);
            }
        }

        return res;
    }
};