#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Step 1: Create a hash map to store number -> index mapping
        // unordered_map provides O(1) average time for insert and lookup
        unordered_map<int, int> map;
        
        // Step 2: Iterate through the array once
        for (int i = 0; i < nums.size(); i++) {
            
            // Step 3: Calculate what number which is needed to reach the target
            int complement = target - nums[i];
            
            // Step 4: Check if the compliment has already been seen in the map
            // If yes, pair has been found!
            if (map.find(complement) != map.end()) {
                // Return the two indices: previous index and current index
                return {map[complement], i};
            }
            
            // Step 5: If complement not found, store current number and its index
            // This is to be done AFTER checking so we don't use same element twice
            map[nums[i]] = i;
        }
        
        // Step 6: If no solution found
        return {};
    }
};