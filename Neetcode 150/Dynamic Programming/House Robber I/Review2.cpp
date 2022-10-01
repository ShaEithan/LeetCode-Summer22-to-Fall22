#include <vector>

using namespace std;

class Solution {
public:
    // 09/30/2022 House Robber (Medium)
    // Time Complexity: O(N), traverse through N houses
    // Space Complexity: O(1)
    int rob(vector<int>& nums) {
        // integers that keep track of the amount that we're robbing and 
        // the current amount we have robbed 
        int robThis = 0, nextHouse = 0;
        int currentRobbed; // updates as we decide which homes to rob this keeps track of who we choose to rob
        
        // go through ecah home and decide which home to rob based on the amounts
        for (int i = 0; i < nums.size(); i++) {
            currentRobbed = max(robThis + nums[i], nextHouse);
            robThis = nextHouse;
            nextHouse = currentRobbed; // when we change nextHouse to currentRobbed, even if we
            // traverse through to the next consequtive house because nextHouse will still be a greater amount.
            // we won't get caught yet
        }
        
        return nextHouse;
    }
};