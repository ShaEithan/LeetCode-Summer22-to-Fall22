#include <vector>

using namespace std;

class Solution {
public:
    // 10/10/2022 Maximum Subarray
    // Time Complexity: O(N) need to iterate over array of nums once
    // Space Compleixty: O(1) no extra space needed 
    int maxSubArray(vector<int>& nums) {
        // start our result and currentSum at first index of the array
        int result = nums[0], currentSum = nums[0];
        
        
        // iterate over the array
        // to calculate the max sum 
        for (int i = 1; i < nums.size(); i++) {
            // decide if we want to add the next element in succession
            // or if we want to start over at the next one
            currentSum = max(currentSum + nums[i], nums[i]);
            
            // then compare if we have found a new largest sum
            result = max(result, currentSum);
        }
        
        return result;
    }
};