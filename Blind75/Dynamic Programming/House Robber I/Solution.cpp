#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 198. House Robber (Medium) O(N), O(1) Dynamic Programming
    int rob(vector<int>& nums) {
        // initialize variables to keep track of our last # of total money robbed
        // and our currentMax amount
        int previousRobbed = 0, currentRobbed = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // find the next maximum amount
            // either our previous amount plus the new house will be greater
            // or our previous amount will be greater
            int currentMaxRobbed = max(nums[i] + previousRobbed, currentRobbed);
            previousRobbed = currentRobbed; // we're moving to the next house so we make previousamount = currentamount
            currentRobbed = currentMaxRobbed; // now our currentMax amount will be change depending on 
            // the new current maximum robbed
        }
        
        // when we get to the end, the currentMax will be the last element calculated
        // so we return our currentamount robbed
        
        // Time Complexity: O(N) because we just need one pass through the array
        // Space Complexity: O(1)
        return currentRobbed;
        
    }
};