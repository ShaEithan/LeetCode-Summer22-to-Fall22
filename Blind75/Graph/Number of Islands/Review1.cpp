#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 07/30/2022 
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int numRows = grid.size(); // finding our total number of rows
        int numColumns = grid[0].size(); // finding our total number of columns
        
        int numIslands = 0; // returning variable for the number islands
        
        
        // going through binary grid
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                
                if (grid[i][j] == '1') { // if we find. land, call DFS to visit all adjacent areas to the current spot
                    dfs(grid, i, j, numRows, numColumns);
                    numIslands++; // we found an island so add one! 
                }
                
                // if we end up finding another island, that means that once dfs is called on all current '1's of the first island we found
                // then this is actually a new island as all land attatched to the first one has turned into a '0' for visited
            }
        }
        
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char>> &grid, int currentRow, int currentColumn, int totalRows, int totalColumns) {
        
        // base case to stop traversal: if the area is water, or if the current index is not in bounds we stop
        if (currentRow >= totalRows || currentColumn >= totalColumns || currentRow < 0 || currentColumn < 0 || grid[currentRow][currentColumn] == '0') {
            return;
        }
        
        grid[currentRow][currentColumn] = '0'; // "marked" as visited
        
        
        // perform dfs on all NSEW directions
        dfs(grid, currentRow + 1, currentColumn, totalRows, totalColumns);
        dfs(grid, currentRow - 1, currentColumn, totalRows, totalColumns);
        dfs(grid, currentRow, currentColumn + 1, totalRows, totalColumns);
        dfs(grid, currentRow, currentColumn - 1, totalRows, totalColumns);
    }
};