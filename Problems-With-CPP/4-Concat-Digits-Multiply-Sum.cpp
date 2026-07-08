// File: solution.cpp
class Solution {
public:
    long long sumAndMultiply(int n) {
        // Handle special case when n is 0
        if (n == 0) {
            return 0;
        }
        
        long long x = 0;           // Will store the final number formed by non-zero digits
        long long sum = 0;         // Sum of the non-zero digits
        long long reversed_x = 0;  // Temporary to build reversed number
        
        // Step 1: Extract digits from right to left
        // Build reversed_x and calculate sum
        while (n > 0) {
            int digit = n % 10;    // Get the last digit
            
            if (digit != 0) {      // Ignore zeros
                sum = sum + digit;                    // Add to sum
                reversed_x = (reversed_x * 10) + digit; // Build reversed number
            }
            
            n = n / 10;            // Remove the last digit
        }
        
        // Step 2: Reverse the reversed_x to get correct order
        // Example: reversed_x = 4321 → x = 1234
        while (reversed_x > 0) {
            int digit = reversed_x % 10;
            x = x * 10 + digit;
            reversed_x = reversed_x / 10;
        }
        
        // Step 3: Return the required result
        return x * sum;
    }
};