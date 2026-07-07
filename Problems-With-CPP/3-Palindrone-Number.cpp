class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: Handle negative numbers [cite: 59]
        if (x < 0) {
            return false;
        }
        
        int original_num = x;
        long reversed_num = 0; // Prevent integer overflow
        
        // Step 3: Run the loop to reverse the number [cite: 60]
        while (original_num > 0) {
            int remainder = original_num % 10;
            
            reversed_num = reversed_num * 10 + remainder; 
            
            original_num = original_num / 10;
        }
        
        // Step 4: Check if the reversed version matches the original [cite: 61]
        return x == reversed_num;
    }
};