#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // 10/06/2022 Rotten Oranges (Medium) Graph BFS
    // Time Complexity: O(m * n), need to traverse over every node once
    // Space Complexity: O(m *n), if every node in the grid is an orange, we
    // may need space for all m * n elements in our queue
    
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        // initialize a queue to keep track of our rotten oranges
        queue<pair<int, int>> rottenq;
        // also need to keep track of how many fresh oranges are inside the grid
        int fresh = 0;
        
        // go through the grid and push rotten orange locations into the queue
        // and count how many fresh oranges there are in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols ; j++) {
                // if rotten push location into queue
                // if fresh increment fresh counter
                if (grid[i][j] == 2) {
                    rottenq.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // mark start of a minute
        rottenq.push({-1, -1});
        
        // initialize the amount of time it takes to rot all oranges
        // return -1 if not 
        int result = -1;
        
        
        // initialize array of directions to traverse
        vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // begin bfs
        while (!rottenq.empty()) {
            // get location of current rotten orange
            int curRow = rottenq.front().first;
            int curCol = rottenq.front().second;
            rottenq.pop();
            
            // if we find where we marked the minute
            // 1 minute has passed so we need to mark the start of 
            // another one
            if (curRow == -1) {
                result++;
                
                if (!rottenq.empty()) {
                    rottenq.push({-1, -1});
                }
                
            } else {
                // traverse in 4 adjacent directions of the rotten orange
                for (int i = 0; i < direct.size(); i++) {
                    int row = curRow + direct[i][0];
                    int col = curCol + direct[i][1];
                    
                    // make sure we're in bounds
                    if (row < 0 || row >= rows || col < 0 || col >= cols) {
                        continue;
                    }
                    
                    // if there's a fresh orange next to the current rotten one
                    if (grid[row][col] == 1) {
                        // contaminate fresh orange
                        fresh--;
                        grid[row][col] = 2; // turn fresh to rotten
                        // then we need to push the new rotten orange's location into the queue
                        // to try and contaminate it's neighbors
                        rottenq.push({row,col});
                    }
                }
            }
        }
        
        if (fresh == 0) {
            return result;
        }
        return -1;
    }
};