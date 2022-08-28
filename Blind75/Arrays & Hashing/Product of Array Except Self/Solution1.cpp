#include <vector>

using namespace std;

class Solution {
public:
    
    // Product of Array Except Self (Medium) Arrays 
    
    // Time Complexity: O(N), O(N + N) = O(2N) Two passes over array
    // Space Complexity: O(1)
    
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // initalize our result vector, this will first store 
        // our prefix values (those before nums at current index i)
        
        // then afterwards, we'll find our product of array except nums at index i
        // by multiplying our current result vector at that index, with our current postfix value
        
        
        vector<int> result(nums.size(), 1); // initialize all elements/space in array as 1
        
        int prefix = 1; // set prefix value we'll multiply from to 
        // initalize prefix variables into our result array
        
        for (int i = 0; i < nums.size(); i++) {
            result[i] = prefix; // setting our prefix value into the result array
            prefix = prefix * nums[i]; // redefining prefix so that we can input the 
            // prefix for the next index in our output array
        }
        
        int postfix = 1; // set postfix value we will multiply from
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = result[i] * postfix; // multiplying our prefix and postfix without nums at 
            // that index
            postfix = postfix * nums[i]; // finding the next postfix product to multiply to find
            // our next product of array except nums at that index
        }
        
        return result;
    }
};