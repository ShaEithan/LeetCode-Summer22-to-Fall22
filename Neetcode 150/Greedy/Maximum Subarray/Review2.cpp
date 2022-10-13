#include <vector>
using namespace std;

class Solution {
public:
    // 10/12/2022 Maximum Subarray (Medium)
    
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(currentSum + nums[i], nums[i]);
            if (currentSum > result) {
                result = currentSum;
            }
        }
        
        // Time Complexity: O(N), iterate through array of N elements
        // Space: O(1), don't need any extra space.
        return result;
    }
};