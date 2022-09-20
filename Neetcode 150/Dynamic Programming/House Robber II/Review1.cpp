#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() < 2) {
            return nums[0];
        }
        
        return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
    }
    
private:
    int rob1(vector<int> &nums, int leftBound, int rightBound) {
        int amount1 = 0, amount2 = 0, currentMax = 0;
        
        for (int i = leftBound; i < rightBound; i++) {
            currentMax = max(amount1 + nums[i], amount2);
            amount1 = amount2;
            amount2 = currentMax;
        }
        
        return amount2;
    }
};