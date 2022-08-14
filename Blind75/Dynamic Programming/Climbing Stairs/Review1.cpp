#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        
        if (n == 1) {
            return 1;
        }
        
        int *dp = new int[n+1]; // array to store the distinct ways to reach a subproblem to calculate the next number of distinct ways to reach a # of steps
        
        
        // 1 step and 2 steps are already calculated, as we have the option to either use 
        // 1 or two steps. 
        
        dp[1] = 1;
        dp[2] = 2;
    
        
        // solving our subproblems by adding two previous sub problems together
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        
        // our last index of our dynamic array should be our answer, as we only caluclated subproblems to that point.
        return dp[n];
        
        // Time Complexity: O(N), need to solve N ssub problems to get the number of ways to reach N steps
        // Space Complexity: O(N), need to save N subproblems
    }
};