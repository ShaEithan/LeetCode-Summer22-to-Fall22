#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 08/05/2022 Product of Array Except Self (Medium)
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> answer(nums.size(), 1);
        
        int prefix = 1;
        for (int i = 0; i < answer.size(); i++) {
            answer[i] = prefix;
            prefix = nums[i] * prefix;
        }
        
        int postfix = 1;
        
        for (int i = answer.size() - 1; i >= 0; i--) {
            answer[i] = answer[i] * postfix;
            postfix = nums[i] * postfix;
        }
        
        return answer;
    }
};