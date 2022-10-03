#include <vector>

using namespace std;

class Solution {
public:
    // 10/01/2022 Unique Paths (Medium) Dynamic Programming
    
    // Time Complexity: O(m * n) because we need to traverse over m * n elements and do operations on them
    // Space Complexity: O(m * n) as we need to have m * n elements of space 
    // in our grid
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // fill out the edges with 1 because each edge has only one unique path
        
        // filling out the left edge
        
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        
        // filling out the top edge
        for (int i = 0; i < n; i++) {
            grid[0][i] = 1;
        }
        
        // finding the # of unique paths using previously solved problems
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        
        // return grid at [m-1][n-1] because that's where our destination is 
        // by the time we reach this, we'll have calculated how many unique paths there are 
        return grid[m - 1][n - 1];
    }
};