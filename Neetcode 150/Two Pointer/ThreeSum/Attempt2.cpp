#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 08/16/2022 ThreeSum (Medium)  O(n^2), O(1)
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() < 3) {
            return result; // no triplets possible
        }
        
        sort(nums.begin(), nums.end()); // sort array
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) { // if the first value is greater than 0, then we just stop completely
                // as we've made it to a point where all numbers after this will add to beyond 0
                break;
            }
            
            if (i > 0 && nums[i - 1] == nums[i]) {
                // keep traversing until our first value is not a duplicate
                continue;
            }
            
            int left = i + 1; // initalize 2 pointers 
            int right = nums.size() - 1;
            
            while (left < right) {
                // caluclate currentSum
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // can increment/deincrement 2 pointers based on if currentSum is < or > than 0
                // ONLY BECAUSE ITS SORTED
                
                if (currentSum < 0) { // increment left to get a bigger sum
                    left++;
                } else if (currentSum > 0) { // increment right to get a smaller sum
                    right--;
                } else { // if currentSum == 0
                    
                    result.push_back({nums[i], nums[left], nums[right]}); // push into result vector
                    
                    
                    // then find the next two non duplicate values  to calculate a new currentSum for the 
                    // next iteration
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                
                    left++;
                
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                
                    right--;
                } 
            }
        }
        
        return result; // return result;
    }
};