#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/09/2022 3Sum (Medium) 
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort num array to deal with duplicates
        // takes O(nlogn) time
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // check if the first number is a duplicate, if it is continue iterating 
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            // use two pointers
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // depending on the value of currentSum do
                if (currentSum ==  0) {
                    // pushback and then iterate to set up for the next values to caluclate our current sum with
                    // iterate one more time after to ensure we have new values 
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (currentSum > 0) { // sum is greater than 0, and because array is sorted, to get a smaller sum we 
                    // deincrement the right poitner as larger ints are on the right side
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        
        return result;
    }
};