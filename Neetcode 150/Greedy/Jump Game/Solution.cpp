#include <vector>

using namespace std;

class Solution {
public:
    // 10/10/2022 Jump Game (Medium) Greedy
    // O(N) Time Complexity because we only need one pass of the array
    // O(1) Space, no extra space needed
    
    bool canJump(vector<int>& nums) {
        // Assumptions: At each index of nums, it gives us the
        // maximum jump length at that position, which means
        // that we can make a jump smaller than that
        
        // initalize array size and create our "goal" index at the end 
        // of our array
        
        int arraySize = nums.size(), goalPost = arraySize - 1;
        
        // as we iterate right to left we're going to check
        // if we can reach our current goal index
        
        for (int i = arraySize - 1; i >= 0; i--) {
            if (i + nums[i] >= goalPost) { // if we can reach the current goal index
                goalPost = i; // then we make the new goal our current index
            } 
        }
        
        // when we get to the beginning of the array, that means we can reach
        // reach the last index from the first index. (goal == 0)
        
        if (goalPost == 0) {
            return true;
        } 
        
        return false;
        
        
    }
};