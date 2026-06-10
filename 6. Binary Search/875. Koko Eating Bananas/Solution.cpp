#include <vector>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int min = 1;
        int max = *std::max_element(piles.begin(), piles.end());

        while (min < max)
        {
            int middle = min + (max - min) / 2;
            int eatingTime = eatBananas(piles, middle);
            if (eatingTime <= h) max = middle;
            else min = middle + 1;
        }

        return min;
    }

    int eatBananas(std::vector<int>& piles, int speed)
    {
        int time = 0;
        for (int pile : piles) time += (pile + speed - 1) / speed;
        return time;
    }
};