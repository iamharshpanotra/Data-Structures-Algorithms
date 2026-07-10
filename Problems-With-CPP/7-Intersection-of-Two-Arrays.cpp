#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Create an unordered_set to store unique elements from nums1
        // This automatically handles duplicates in nums1
        unordered_set<int> bag(nums1.begin(), nums1.end());
        
        // Step 2: Create a result vector to store the intersection elements
        vector<int> result;
        
        // Step 3: Iterate through each element in nums2
        for (int i = 0; i < nums2.size(); i++){
            int current_num = nums2[i];
            
            // Step 4: Check if current_num exists in the set (i.e., present in nums1)
            // bag.count() returns 1 if element exists, 0 otherwise
            if (bag.count(current_num) > 0){
                // Step 5: Add the common element to result
                result.push_back(current_num);
                
                // Step 6: Remove the element from set to ensure uniqueness
                // This prevents adding the same number again if it appears multiple times in nums2
                bag.erase(current_num);
            }
        }
        
        // Step 7: Return the result containing unique intersection elements
        return result;
    }
};
