#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // set to store numbers already iterated over
        unordered_set<int> number_set;
        
        for (int i = 0; i < nums.size(); i++) {
            // if we haven't found the number already, add it to the set
            if (number_set.find(nums[i]) == number_set.end()) {
                number_set.insert(nums[i]);
                // if not we found a duplicate
            } else {
                return true;
            }
        }
        
        return false;
    }
    
    // Time Complexity: O(N), need to iterate N elements to find there are no duplicates worst case
    // Space Complexity: O(N), need to have N numbers in unordered set
};