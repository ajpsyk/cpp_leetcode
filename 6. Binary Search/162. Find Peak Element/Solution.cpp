class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (true)
        {
            int middle = left + (right - left) / 2;
            int value = nums[middle];
            double look_left = (middle - 1 < 0) ? -INFINITY : nums[middle - 1];
            double look_right = (middle + 1 > nums.size() - 1) ? -INFINITY : nums[middle + 1];

            if (value > look_left and value > look_right)
            {
                return middle;
            }

            if (look_left > value)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
    }
};