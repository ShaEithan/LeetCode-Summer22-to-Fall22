#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 07/30/2022 Review #1
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result; // vector that returns the two indices that add to the target
        
        
        // hash map that keeps track of current values and their indexes
        unordered_map<int,int> myMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int neededValue = target - nums[i]; // calcultes the value we need to add to the target with our current integer in the array
            
            if (myMap.find(neededValue) != myMap.end()) { // if we find the value we're looking for then return the indexes
                return {myMap[neededValue], i};
            } else {
                myMap[nums[i]] = i; // if we can't find the value add the current value to the hashmap
            }
        }
        
        return result; // return the result value, even if it's empty.
        
        // Time Complexity: O(N), need to pass over array once
        // Space Complexity: O(N), worst case no values add up to target so we have n elements in our hashmap
    }
};