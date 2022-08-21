#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 08/17/2022 Container with Most Water (Medium) O(N), O(1)
    int maxArea(vector<int>& height) {
        
        // if the height array is empty, just return 0. No water can be stored
        if (height.empty()) {
            return 0;
        }
        
        // initalize our two pointers
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        
        // iterate until our pointers meet, so it's in O(N) time
        while (left < right) {
            // calculate area between the two vertical liens
            int currentWater = (right - left) * min(height[left], height[right]);
            maxWater = max(currentWater, maxWater); // find our new maximum amount of water
            
            // traverse each pointer depending on whichever has the lower height
            // so we can get the best height for each vertical line and keep our current "tallest" line
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};