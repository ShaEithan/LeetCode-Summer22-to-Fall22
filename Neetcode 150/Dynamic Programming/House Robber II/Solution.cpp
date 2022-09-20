#include <vector>

using namespace std;

// House Robber 2 DP (Medium)
class Solution {
public:
    int rob(vector<int>& nums) {
        
        // if there aren't two houses, then
        // we just return the value of the first and only house
        if (nums.size() < 2) {
            return nums[0];
        }

        // run House Robber 1 Solution twice and take the max of it for
        // our max robbed

        // the first and last house are adjacent since houses are in a circle
        // so we can't rob them both in one iteration

        // first call is first house to the house before the last house
        // last call is the 2nd house to the last house
        int result = max(rob1(nums, 0, nums.size() - 1), rob1(nums,1, nums.size()));
        
        return result;

        // Time Complexity: O(N), need to do helper funciton twice
        // so N + N = O(N)
        // Space Complexity: O(1)
    }
    
private:
    int rob1(vector<int> &nums, int leftIndex, int rightIndex) {
        
        int house1 = 0, house2 = 0, currentRobbed;
        
        for (int i = leftIndex; i < rightIndex; i++) {
            currentRobbed = max(nums[i] + house1, house2);
            house1 = house2;
            house2 = currentRobbed;
        }
        
        
        return currentRobbed;
    }
};