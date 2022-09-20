#include <vector>

using namespace std;

class Solution {
public:
    // 39. Combination Sum (Medium) Backtracking
    
    // Time Complexity: O(2^target) because the maximum number of calls at once are the height of our recursion tree, so target
    // is the max value and we need to go through all possibilities
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort our candidates array, so it's easier to keep track of how our currentSum 
        // compares to our target. 
        
        vector<vector<int>> result; // result vector
        vector<int> current; // array to keep track of current elements on each path
        
        dfs(candidates, target, 0, 0, current, result);
        return result;
    }
    
    void dfs(vector<int> &candidates, int target, int currentSum, int currentIndex, vector<int> &current, vector<vector<int>> &result) {
        // stop traversal if our currentSum is > target
        if (currentSum > target) {
            return;
        }
        
        // if currentSum == target, push path(combination) into our result
        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        
        // for every pass, we push our current element starting at the current index
        // then continue doing dfs but by adding the value of the current element our array
        // we pop back because if we don't backtrack, we'd miss combinations, and we'd end traversal early
        
        for (int i = currentIndex; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            dfs(candidates, target, currentSum + candidates[i], i, current, result);
            current.pop_back();
        }
        
        // This is how it looks for three full iterations in dfs
        // 2 3 4
        // 2,2 2,3 2,4
        // 2,2,2 2,2,3 2,2,4
        
        return;
    }
};