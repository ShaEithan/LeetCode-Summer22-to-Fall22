#include <vector>

using namespace std;

class Solution {
public:
    // 10/12/2022 Combination Sum (Medium) Backtracking
    
    // Time Complexity: O(2^target), because the maximum number of calls are the height of our recursion tree
    //  and we and target is the max value and we need to account for all possiblities
    // Space Complexity: O(Target/M)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end()); // O(nlogn) 
        
        vector<vector<int>> result;
        vector<int> currentCombo;
        backTracking(candidates, currentCombo, result, 0, target);
        
        return result;
    }
    void backTracking(vector<int> &candidates, vector<int> &currentCombo, vector<vector<int>> &result, int currentIndex, int target) {
        // reverse summation
        if (target == 0) {
            result.push_back(currentCombo);
        }

        if (target < 0) {
            return;
        }
        
        // if target is > 0, we keep traversing
        
        /*
            2
           / \
         2,2  3
        /   \   \
      2,2,2  2,2,3 4 
        */
        for (int i = currentIndex; i < candidates.size(); i++) {
            int currentVal = candidates[i];
            currentCombo.push_back(currentVal);
            backTracking(candidates, currentCombo, result, i, target - currentVal);
            currentCombo.pop_back();
        }
        
        return;
    }
};