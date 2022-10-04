#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));
        
        // start by traversing the right and leftmost columns
        // leftmost touches pacific
        // rightmost touches atlantic 
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0, rows, cols);
            dfs(heights, atlantic, i, cols - 1, rows, cols);
        }
        
        // traverse over the top and bottom of our matrix 
        
        for (int j = 0; j < rows; j++) {
            dfs(heights, pacific, 0, j, rows, cols);
            dfs(heights, atlantic, rows - 1, j, rows, cols);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int currentRow, int currentCol,
            int maxRow, int maxCol) {
        
        visited[currentRow][currentCol] = true;
        
        // make sure we're in bounds and that we haven't already marked this location as possible to touch the ocean
        // and that the next location is greater than or equal to the current location's height
        if (currentRow > 0 && !visited[currentRow - 1][currentCol] && heights[currentRow - 1][currentCol] >= heights[currentRow][currentCol]) {
            dfs(heights, visited, currentRow - 1, currentCol, maxRow, maxCol);
        }
        if (currentRow < maxRow - 1 && !visited[currentRow + 1][currentCol] && heights[currentRow + 1][currentCol] >= heights[currentRow][currentCol]) {
            dfs(heights, visited, currentRow + 1, currentCol, maxRow, maxCol);
        }
        if (currentCol > 0 && !visited[currentRow][currentCol - 1] && heights[currentRow][currentCol - 1] >= heights[currentRow][currentCol]) {
            dfs(heights, visited, currentRow, currentCol - 1, maxRow, maxCol);
        }
        if (currentCol < maxCol - 1 && !visited[currentRow][currentCol+ 1] && heights[currentRow][currentCol + 1] >= heights[currentRow][currentCol]) {
            dfs(heights, visited, currentRow, currentCol + 1, maxRow, maxCol);
        }
        
        return;
    }
};