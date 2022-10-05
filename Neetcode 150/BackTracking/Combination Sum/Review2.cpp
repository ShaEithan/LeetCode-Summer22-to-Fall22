#include <vector>
using namespace std;

class Solution {
public:
    // 10/05/2022 Combination Sum (Medium)
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort candidates array to make it easier to determine duplicates
        vector<int> currentPath;
        vector<vector<int>> result;
        dfs(candidates, currentPath, result, 0, target, 0); // begin traversal of our recursion tre
        return result;
    }
    void dfs(vector<int> &candidates, vector<int> &currentPath, vector<vector<int>> &result, int currentSum, int target, int currentIndex) {
        // if we go over the target we can stop traversal
        if (currentSum > target) {
            return;
        }
        
        // if we get the target value, push that path into our result
        if (currentSum == target) {
            result.push_back(currentPath);
            return;
        }
        
        // otherwise we do backtracking by adding current value beginning at the current index
        // do dfs on that with the new sum and then pop it to ensure we have all combinations
        for (int i = currentIndex; i < candidates.size(); i++) {
            currentPath.push_back(candidates[i]);
            dfs(candidates, currentPath, result, currentSum + candidates[i], target, i);
            currentPath.pop_back();
        }
        
        return;
    }
    
};