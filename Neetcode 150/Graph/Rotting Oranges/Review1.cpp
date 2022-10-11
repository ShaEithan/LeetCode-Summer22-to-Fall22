#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 10/10/2022 Rotting Oranges (Medium) Graph BFS
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> rotten;
        int fresh = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                
                if (grid[i][j] == 2) {
                    rotten.push({i,j});
                }
            }
        }
        
        rotten.push({-1, -1});
        
        // set minutes as -1, as we've yet to begin the rottenening process
        int minutes = -1;
        
        // initialize a vector of directions to add to our current rotten orange indices
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0 ,1}};
        
        // begin our bfs traversal through the grid
        while (!rotten.empty()) {
            int curRow = rotten.front().first, curCol = rotten.front().second;
            rotten.pop();
            
            // check if we're at our minute mark
            if (curRow == -1) {
                minutes++; // increment minutes passed
                
                if (!rotten.empty()) {
                    rotten.push({-1,-1}); // push another minute marker into the queue if
                    // there aren't any more rotten oranges to traverse
                }
            
            } else { // means we're going to traverse from our current rotten orange
                
                for (int i = 0; i < directions.size(); i++) {
                    // get indices of adjacent orange
                    int row = curRow + directions[i][0];
                    int col = curCol + directions[i][1];
                    
                    // make sure we're in bounds
                    if (row < 0 || row >= rows || col < 0 || col >= cols) {
                        continue;
                    }
                    
                    // check if it's fresh and turn it rotten
                    if (grid[row][col] == 1) {
                        grid[row][col] = 2;
                        fresh--;
                        rotten.push({row,col});
                    }
                }
            }
        }
        
        if (fresh == 0) {
            return minutes;
        }
        
        return -1;
    }
    
};