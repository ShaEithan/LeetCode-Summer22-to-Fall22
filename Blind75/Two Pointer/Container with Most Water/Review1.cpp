#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // 08/20/2022 Container with Most Water (Medium) 
    int maxArea(vector<int>& height) {
        
        if (height.size() < 2) { // if we don't have enough elements to caluclate area, then just return 0
            return 0;
        }
        
        int left = 0, right = height.size() - 1, maxArea = 0; // initalize our two pointers and area
        
        while (left != right) {
            maxArea = max(maxArea, (right - left) * (min(height[left], height[right]))); // calculate and compare to find our max area
            
            if (height[left] < height[right]) { // depending on which pointer has the smaller height, then increment as needed
                left++;
            } else {
                right--;
            }
        }
        
        // Time Complexity: O(N), need to pass over array once
        // Space Complexity: O(1)
        return maxArea;
    }
};