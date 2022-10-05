#include <vector>

using namespace std;

class Solution {
public:
    // 53. Maximum Subarray (Medium)
    // Time Complexity: O(N), need only one pass through nums array
    // Space Complexity: O(1), no extra space needed
    
    int maxSubArray(vector<int>& nums) {
        // use to variables to keep track of what we want to return and 
        // our currentSum
        
        int currentSum = nums[0], result = nums[0];
        
        // iterate through the rest of the array
        
        for (int i = 1; i < nums.size(); i++) {
            // see if we should restart the sum or continue by adding the current element to our currentSum
            currentSum = max(currentSum + nums[i], nums[i]);
            result = max(result, currentSum); // set our result depending on if our currentSum or current result is 
            // larger
        }
        
        return result;
    }
};