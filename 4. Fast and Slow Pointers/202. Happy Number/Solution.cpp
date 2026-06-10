class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (true)
        {   
            slow = square_then_sum_digits(slow);
            fast = square_then_sum_digits(square_then_sum_digits(fast));
            if (fast == 1) return true;
            if (slow == fast) return false;   
        }
    }

    int square_then_sum_digits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += (digit) * (digit);
            n /= 10;
        }
        return sum;
    }
};