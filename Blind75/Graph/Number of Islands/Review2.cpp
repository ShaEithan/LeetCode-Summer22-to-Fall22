#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 08/20/2022 Number of Islands (Graph) Medium O(N^2) O(1)
    int numIslands(vector<vector<char>>& grid) {
        int numberIslands = 0, totalRows = grid.size(), totalColumns = grid[0].size();
        
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalColumns; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, totalRows, totalColumns);
                    numberIslands++;
                }
            }
        }
        
        return numberIslands;
    }
    
private:
    void dfs(vector<vector<char>> &grid, int currentRow, int currentColumn, int totalRows, int totalColumns) {
        
        if (currentRow >= totalRows || currentColumn >= totalColumns || currentRow < 0 || currentColumn < 0 || grid[currentRow][currentColumn] == '0') {
            return;
        }
        
        grid[currentRow][currentColumn] = '0';
        
        dfs(grid, currentRow + 1, currentColumn, totalRows, totalColumns);
        dfs(grid, currentRow - 1, currentColumn, totalRows, totalColumns);
        dfs(grid, currentRow, currentColumn + 1, totalRows, totalColumns);
        dfs(grid, currentRow, currentColumn - 1, totalRows, totalColumns);
    }
};