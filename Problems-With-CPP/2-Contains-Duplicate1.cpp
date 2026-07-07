#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create an unordered_set to store numbers
        // Think of it as a "bag" that only holds unique items
        unordered_set<int> bag;
        
        // Iterate through every number in the input array
        for (int i = 0; i < nums.size(); i++) {
            // Check if current number is already in the bag
            // bag.count(x) returns 1 if x exists, 0 otherwise
            if (bag.count(nums[i]) > 0) {
                // Duplicate found! Return true immediately
                return true;
            }
            
            // Number is new, add it to the bag of seen numbers
            bag.insert(nums[i]);
        }
        
        // If the loop finished , and no duplicates were found
        return false;
    }
};

// The difference in vector<int>& and vector<int> is in how the parameter is passed:

// vector<int>& nums → pass by reference. The function works directly on the original vector, no copy is made (faster, less memory).

// vector<int> nums → pass by value. The function receives a copy of the vector, which is slower and uses more memory.

// So: & avoids copying, no & makes a copy.