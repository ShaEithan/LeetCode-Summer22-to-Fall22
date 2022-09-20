class Solution {
public:
    // 09/03/2022 Climbing Stairs (Easy) Dynamic Programming
    int climbStairs(int n) {
        if (n == 1) { // base case, if n == 1 then we just return 1 nothing else needs to be done
            return 1;
        }
        
        //initalizing our dynamic dp array for bottom up approach
        int *dp = new int[n+1];
        
        // first two steps are already defined
        dp[1] = 1;
        dp[2] = 2;
        
        // use last 2 solved sub problems to solve next subproblem until we get to the end
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        
        return dp[n]; // last element in the array is our output
        
        // Time Complexity: O(N), need to perform operations N times
        // Space Complexity: O(N), dynamic dp array of size N 
    }
};