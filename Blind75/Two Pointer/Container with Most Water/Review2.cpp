#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    // 08/24/2022 Container with Most Water (Medium) O(N) O(1)
    // Time Complexity: O(N), need to traverse N elements
    // Space Complexity: O(1)
    
    int maxArea(vector<int>& height) {
        
        if (height.size() < 2) { // not enough entries means we can't calculate area
            return 0;
        }
        
        int left = 0, right = height.size() - 1, maximumArea = 0;
        
        while (left < right) { // when left == right, then we've gone through the array
            // calculate currentArea and then find the maximumArea
            int currentArea = (right - left) * min(height[left], height[right]);
            
            maximumArea = max(currentArea, maximumArea);
            
            // depending on which height is higher, then we traverse each poitner
            // if left > right, we need to traverse right
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        
        return maximumArea; // return maximum area
    }
};