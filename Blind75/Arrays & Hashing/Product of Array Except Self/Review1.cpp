#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 08/28/2022 Product of Array Except Self (Medium) O(N), O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1); // vector we will be returning and making changes to
        
        int prefix = 1; // prefixes are the product of all values before nums at index i
        // initialize as 1 because there are no values before the first element of our nums array
        
        // iterate left to right
        for (int i = 0; i < result.size(); i++) { // O(N)
            result[i] = prefix; 
            prefix = prefix * nums[i]; // multiply current index's value, so we can set the prefix for our
            // next value
        }
        
        int postfix = 1; // postfix is the product of all values to the right of our current index
        // we're going to iterate from right to left, so there are no values after the last element in the array
        
        for (int i = result.size() - 1; i >= 0; i--) { // O(N)
            result[i] = result[i] * postfix; // to find product of other than nums[i], we multiply prefix * postfix. the 
            // prefix is what is currently stored in our result array
            postfix = postfix * nums[i]; // set up the next postfix product for the next element in our array
        }
        
        return result;
    }
};