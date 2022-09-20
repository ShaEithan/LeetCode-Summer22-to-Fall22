#include <vector>

using namespace std;

class Solution {
public:
    // 09/03/2022 Container with Most Water (Medium) O(N) O(1)
    int maxArea(vector<int>& height) {
        
        // initalize our pointers and where we keep our maxWater
        int left = 0, right = height.size() - 1, maxWater = 0;
        
        // iterate two pointers until they meet meaning we've traversed the entire array
        while (left < right) {
            // calcualte the max water and compare it with our current
            // width = right index - left index length = minimum height between two pointers
            // as the box cannot slant
            
            maxWater = max(maxWater, (right - left) * min(height[left],height[right]));
            
            // traverse the pointer that has the smaller height to ensure we find the optimal
            // area for each calculation
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};