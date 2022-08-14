#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 07/29/2022 - Number of Islands (Medium)
    
    // Time Complexity: O(M X N), where M is the number of rows
    // and N is the number of columns
    
    // Space Complexity: worrst case O(M X N) in the case that
    // the grip map is filled with lands wheree DFS goes M X N deep


    int numIslands(vector<vector<char>>& grid) {

        // initialize variables thaat show the # of rows and # of columns
        // a grid has
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0; // returns the number of islands
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') { // if the current element is island
                    dfs(grid, i, j, m, n); // perform dfs to check adjacent areas in the matrix
                    result++; // increment the # of islands by 1
                }
            }
        }
        
        return result;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        
        // Base Case: Stop dfs traversal if the current row is not in bounds,
        // if the currentColumn is not in bounds, or ifthe current element accessed
        // is water '0'
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0'; // mark the current element as water because we've already visited it
        

        // traverse and check elements in N S E W directions of the current element
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};
