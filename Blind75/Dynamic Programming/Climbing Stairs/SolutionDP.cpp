#include <iostream>

using namespace std;

class Solution {
public:
    
    // 07/29/2022 Climbing Stairs (Easy) DP
    
    // Time Complexity: O(N), need a single loop until N
    // Space Complexity: O(N), dp array of size n is used
    int climbStairs(int n) {
        
        // base case: if n == 1, we only have one option
        // to traverse
        
        if (n == 1) {
            return 1;
        }
        
        // initialize space for our dp vector
        // so we can keep track of previous sub problem solutions
        int *dp = new int[n+1];
        
       
        dp[1] = 1;
        dp[2] = 2;
        
        // Solving sub problems by using previous sub problems
        // can reach itth step in 2 ways, taking a single step from (i - 1) th step, and 
        // 2 steps from (i - 2)th step
        
        // so total # of ways to reach ith is equal to sum of ways of reaching
        // (i - 1)th step and reaching (i-2)th step together
        
        // filling out our dp vector
        // all the way to N
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp [i - 2];
        }
        
        // onec we reach the end we should reach and return the ways to reach n steps
        return dp[n];
    }
};