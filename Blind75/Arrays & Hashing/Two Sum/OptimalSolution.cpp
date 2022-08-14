#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // hashmap used to keep track of numbes we've already iterated over
        // on our one pass.
        
        unordered_map<int,int> my_map;
        
        // vector to return our indices
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // needed value = target - currentvalue in the target array
            // calculate the needed value for the current number to sum with to 
            // get the target sum
            int needed_value = target - nums[i];
            
            // check if the needed value is already in the map
            // if it is return the two indices, if not
            // add the current number and it's index to the map
            
            if (my_map.find(needed_value) == my_map.end()) {
                my_map[nums[i]] = i;
            } else {
                result = {my_map[needed_value], i};
                return result;
            }
        }
        
        return result;
        // Time Complexity: O(N), need to pass over N elements in our numbers array
        // Space Complexity: O(N), worst case need to put N elements in the hashmap
        // to find that there aren't two indices that add up to the target sum
    }
};