#include <vector>
#include <unordered_map>

long countTriplets(std::vector<long> arr, long r) {
    std::unordered_map<long, long> right_map;
    std::unordered_map<long, long> left_map;
    long count = 0;
    for (long& num: arr) right_map[num] += 1;
    
    for (long& num : arr)
    {
        right_map[num] -= 1;
        if (num % r == 0)
        {
            count += left_map[num / r] * right_map[num * r];
        }
        left_map[num] += 1;
    }
    
    
    return count;

}