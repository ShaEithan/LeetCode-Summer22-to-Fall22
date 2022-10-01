#include <vector>

using namespace std;

class Solution {
public:
    // 09/28/2022 Number of Islands (Medium)
    
    // Time Complexity: O(N^2) need to visit every single node of the grid
    // Space Complexity: O(N^2) in the event that every single piece of the grid is an island, we need that many calls
    int numIslands(vector<vector<char>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        int result = 0;
        
        for (int i = 0; i < numRows; i++) {
            for(int j = 0; j < numCols; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs(grid, numRows, numCols, i, j);
                }
            }
        }
        
        return result;
    }
    void dfs(vector<vector<char>> &grid, int numRows, int numCols, int currentRow, int currentCol) {
        // check if the current element is within bounds or if it's a piece of the island
        // need to have check for 0 at the end in the event that we are actually out of bounds 
        if (currentRow >= numRows || currentRow < 0 || currentCol >= numCols || currentCol < 0 || grid[currentRow][currentCol] == '0') {
            return;
        }
        
        // then mark the element as visited by turning it into a 0
        grid[currentRow][currentCol] = '0';
        
        // run DFS on 4 adjacent elements to see if they are part of the island or not
        // by the time it's finished the entire island will be marked as '0' so we don't recount the land elements
        
        dfs(grid, numRows, numCols, currentRow - 1, currentCol);
        dfs(grid, numRows, numCols, currentRow + 1, currentCol);
        dfs(grid, numRows, numCols, currentRow, currentCol - 1);
        dfs(grid, numRows, numCols, currentRow, currentCol + 1);
        
        return;
    }
};