#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // get dimensions of matrix
        int rows = heights.size(), cols = heights[0].size();
        
        // initalize our sets to keep track of what elements
        // can reach pacific and atlantic
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));
        
        // use dfs to go through every row and
        // it's edges starting from the top to check
        // what locations can touch the pacific and atlantic
        
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0, rows, cols);
            dfs(heights, atlantic, i, cols - 1, rows, cols);
        }
        
        // go through every column and it's edges and begin dfs traversal from the edges
        // to see what locations can touch the pacific atlantic 
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j, rows, cols);
            dfs(heights, atlantic, rows - 1, j, rows, cols);
        }
        
        vector<vector<int>> result;
        
        // go through grid again and check if the location at (i,j)
        // are both true in our
        // visited arrays. 
        // Means they can both reach the atlantic and pacific
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited,
            int currentRow, int currentCol, int maxRow, int maxCol) {
        
        // mark current location as it can touch whatever ocean the visited
        // array is
        
        visited[currentRow][currentCol] = true;
        
        // Now do DFS in all 4 directions, making sure that we're in bounds depending on what direction
        // and that the height of the current location is less than or equal to the one before it
        // otherwise rain water won't fall that way
        
        // we also make sure that the location it's going to is false, so we don't check a location twice;
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