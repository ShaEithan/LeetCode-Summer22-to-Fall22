#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/12/2022 Product of Array Except Self (Medium)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1); // initializing vector of size n with values of 1
        
        int prefix = 1; // keeps track of product of all elements except the current index
        
        for (int i = 0; i < nums.size(); i++) {  // populate result array with our post fix
            result[i] = prefix;
            prefix *= nums[i];
        } // O(N), one pass over array of size nums
        
        
        int postfix = 1; // postfix is the product of all elements after our current index
        
        for (int i = nums.size() - 1; i >= 0; i--) { // multiply all our prefix values with our postfix values 
            // to get our result
            result[i] *= postfix;
            postfix = nums[i] * postfix;
        } // O(N), 2nd pass over array of size nums
        
        
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        return result;
    }
};