from collections import defaultdict

def countTriplets(arr, r):
    right_freq_map = defaultdict(int)
    left_freq_map = defaultdict(int)
    count = 0

    for num in arr:
        right_freq_map[num] += 1

    for num in arr:
        right_freq_map[num] -= 1
        if num % r == 0:
            count += left_freq_map[num // r] * right_freq_map[num * r]
        left_freq_map[num] += 1
    
    return count