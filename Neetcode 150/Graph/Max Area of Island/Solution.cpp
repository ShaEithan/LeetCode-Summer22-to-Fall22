#include <vector>

using namespace std;
class Solution {
public:
    // 09/28/2022 Max Area of Island (Medium)
    // Time Complexity: O(n^2), need to iterate through n^2 elements in the matrix
    // Space Complexity: O(n^2), at worst all elements are going to be a 1 so we'd have n^2 calls for our dfs
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxRows = grid.size(), maxCols = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < maxRows; i++) {
            for (int j = 0; j < maxCols; j++) {
                if (grid[i][j] == 1) { // each island we find we take the max between the currentMax area and 
                    maxArea = max(maxArea, dfs(grid, maxRows, maxCols, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
    int dfs(vector<vector<int>> &grid, int maxRows, int maxCols, int currentRow, int currentCol) {
        // check if our current element we want to access is within bounds or if it's 0
        if (currentRow >= maxRows || currentRow < 0 || currentCol >= maxCols || currentCol < 0 || grid[currentRow][currentCol] == 0) {
            return 0;
        }
        
        // mark current element visited
        grid[currentRow][currentCol] = 0;
        
        // return 1 (because this element is a piece of land) + the dfs of all the other directions 
        return 1 + dfs(grid, maxRows, maxCols, currentRow - 1, currentCol) + dfs(grid, maxRows, maxCols, currentRow + 1, currentCol) + dfs(grid, maxRows, maxCols, currentRow, currentCol - 1) + dfs(grid, maxRows, maxCols, currentRow, currentCol + 1);
    }
};