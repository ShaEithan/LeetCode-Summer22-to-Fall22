#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));
        
        // start dfs traversal from edges 
        
        // go by row (left to right)
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0, rows, cols);
            dfs(heights, atlantic, i, cols - 1, rows, cols);
        }
        
        // go by column (up and down)
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j, rows, cols);
            dfs(heights, atlantic, rows - 1, j, rows, cols);
        }
        
        vector<vector<int>> result;
        
        // go through array to check where pacific and atlantic are true
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int curRow, int curCol, int maxRow, int maxCol) {
        // make sure we're in bounds and that we haven't visited the location in this visited array yet
        if (curRow < 0 || curCol < 0 || curRow >= maxRow || curCol >= maxCol || visited[curRow][curCol]) {
            return;
        }
        
        // mark location as true that it can touch the ocean
        visited[curRow][curCol] = true;
        
        // do dfs in 4 directions, make sure they're in bounds and then
        // make sure the neighboring element's height is greater than or equal to the currentHeight
        if (curRow > 0 && heights[curRow - 1][curCol] >= heights[curRow][curCol]) {
            dfs(heights, visited, curRow - 1, curCol, maxRow, maxCol);
        }
        
        if (curRow + 1 < maxRow && heights[curRow + 1][curCol] >= heights[curRow][curCol]) {
            dfs(heights, visited, curRow + 1, curCol, maxRow, maxCol);
        }
        
        if (curCol > 0 && heights[curRow][curCol - 1] >= heights[curRow][curCol]) {
            dfs(heights, visited, curRow, curCol - 1, maxRow, maxCol);
        }
        
        if (curCol + 1 < maxCol && heights[curRow][curCol + 1] >= heights[curRow][curCol]) {
            dfs(heights, visited, curRow, curCol + 1, maxRow, maxCol);
        }
        
        return;
    }
};