#include <vector>

using namespace std;

class Solution {
public:
    // 09/27/2022 Combination Sum
    
    // Time Complexity: O(2^target) because the maximum number of calls at once are the height of our recursion tree, so target
    // is the max value and we need to go through all possibilities!
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // O(nlogn), sort as all integers are distinct and helps us keep track of where we are
        vector<vector<int>> result;
        vector<int> currentPath;
        
        dfs(candidates, result, currentPath, 0, target, 0); // begin dfs traversal to find all combinations
        return result;
        
    }
    
    // our dfs to create our recursion tree
    void dfs(vector<int> candidates, vector<vector<int>> &result, vector<int> &currentPath, int currentSum, int target, int currentIndex) {
        
        if (currentSum > target) {  // if we pass our target, then stop traversal
            return;
        }
        
        if (currentSum == target) { // if we find a path that equals the target push it into our result
            result.push_back(currentPath);
            return;
        }
        
        for (int i = currentIndex; i < candidates.size(); i++) { // if the current Sum is still less than our target, then 
            // starting at the currentIndex we push the current element in our path and run DFS again with our new sum
            // for all elements after the current index
            
            // this lets us find all the combinations possible
            currentPath.push_back(candidates[i]);
            dfs(candidates, result, currentPath, currentSum + candidates[i], target, i);
            currentPath.pop_back(); // we need to pop back on every iteration, otherwise we wouldn't get all the combinations without backtracking
        }
        
        return;
    }
};