#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/9/2022 House Robber (Medium)
    int rob(vector<int>& nums) {
        int amount1 = 0, amount2 = 0, currentMax = 0;
        int currentRobbed;
        
        for (int i = 0; i < nums.size(); i++) {
            // calculating the best amount to rob between two houses
            // either we rob the current house or skip it because we still have greater value
            // in the amount we've already robbed
            currentRobbed = max(amount1 + nums[i], amount2);
            amount1 = amount2; // make amount1 amount2 because we're going to be moving onto the next house
            amount2 = currentRobbed; // amount2 becomes the amount that we currently have robbed to keep track
            // of how much we've robbed after each house
        }
        
        // return amount2 or currentRobbed, because once the iteration is over, we'll have the maximum amount
        // we've robbed as we've gone through all the houses
        return amount2;
        
        // Time Complexity: O(N), one iteration through array
        // Space Complexity: O(1)
    }
};