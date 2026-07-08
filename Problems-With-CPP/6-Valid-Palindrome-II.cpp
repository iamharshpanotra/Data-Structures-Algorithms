// solution.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function to check if string can be palindrome after at most one deletion
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Characters match, move towards center
            if (s[left] == s[right]) {
                left++;
                right--;
            } 
            // Mismatch found - we have one chance to delete
            else {
                // Try two possibilities:
                // 1. Delete character at left
                // 2. Delete character at right
                return isPalindrome(s, left + 1, right) || 
                       isPalindrome(s, left, right - 1);
            }
        }
        
        // No mismatch found, string is already palindrome
        return true;
    }
    
    // Helper function to check if substring s[i..j] is palindrome
    // This is used after we skip (delete) one character
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// Test driver (for local testing)
int main() {
    Solution sol;
    
    cout << boolalpha;
    cout << "aba -> " << sol.validPalindrome("aba") << endl;      // true
    cout << "abca -> " << sol.validPalindrome("abca") << endl;    // true
    cout << "abc -> " << sol.validPalindrome("abc") << endl;      // false
    cout << "abcbca -> " << sol.validPalindrome("abcbca") << endl; // true (delete one 'b' or 'c')
    
    return 0;
}