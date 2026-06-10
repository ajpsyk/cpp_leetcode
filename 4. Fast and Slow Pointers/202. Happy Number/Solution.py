class Solution:
    def isHappy(self, n: int) -> bool:
        slow = n
        fast = n

        while True:
            slow = self.next(slow)
            fast = self.next(self.next(fast))
            if fast == 1: return True
            if slow == fast: return False
    
    def next(self, n):
        sum = 0

        while n > 0:
            digit = n % 10
            sum += digit * digit
            n //= 10
        
        return sum