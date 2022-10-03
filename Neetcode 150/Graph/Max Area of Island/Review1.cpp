#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        // get number of Rows and columns and keep track of maxArea
        int maxRows = grid.size(), maxCols = grid[0].size();
        int maxArea = 0;
        
        // iterate through the grid and find islands and run dfs to return
        // the area of each island
        for (int i = 0; i < maxRows; i++) {
            for (int j = 0; j < maxCols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j, maxCols, maxRows));
                }
            }
        }
        
        return maxArea; // return max area
    }
    int dfs(vector<vector<int>> &grid, int currentRow, int currentCol, int maxCol, int maxRow) {
        // check if we're in bounds and check if it's already visited or just water
        if (currentRow < 0 || currentRow >= maxRow || currentCol < 0 || currentCol >= maxCol || grid[currentRow][currentCol] == 0) {
            return 0;
        }
        
        // mark current element as visited so we don't count them twice
        grid[currentRow][currentCol] = 0;
        
        // returns the sum of the elements in the current island
        return 1 + dfs(grid, currentRow - 1, currentCol, maxCol, maxRow) + dfs(grid, currentRow + 1, currentCol, maxCol, maxRow) +
            dfs(grid, currentRow, currentCol - 1, maxCol, maxRow) + dfs(grid, currentRow, currentCol + 1, maxCol, maxRow);
    }
};