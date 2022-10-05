#include <vector>
using namespace std;

class Solution {
public:
    // 10/04/2022 130. Surrounded Regions (Medium)
    
    // Time Complexity: O(n * m), basically need to iterate O(n) + O(m) + o(n * m) -> O(n * m)
    
    void solve(vector<vector<char>>& board) {
        // get dimensions of our grid
        int rows = board.size(), cols = board[0].size();
        
        // look for unsurrounded o's and mark them through dfs starting with the edges
        
        // up and down (by row)
        
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0, rows, cols);
            dfs(board, i, cols - 1, rows, cols);
        }
        
        // left to right (by column) 
        
        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j, rows, cols);
            dfs(board, rows - 1, j, rows, cols);
        }
        
        // now we iterate through the array to check for the unmarked "surrounded" 0's.
        // if the element is 'marked' then we just turn it back into a 0
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
        
        return;
    }
    
    void dfs(vector<vector<char>> &board, int curRow, int curCol, int maxRow, int maxCol) {
        // make sure we're in bounds and that the current board element is O if not continue we don't need to touch it
        if (curRow < 0 || curRow >= maxRow || curCol < 0 || curCol >= maxCol || board[curRow][curCol] != 'O') {
            return;
        }
        
        board[curRow][curCol] = 'E';
        
        // traverse in 4 directions 
        dfs(board, curRow - 1, curCol, maxRow, maxCol);
        dfs(board, curRow + 1, curCol, maxRow, maxCol);
        dfs(board, curRow, curCol - 1, maxRow, maxCol);
        dfs(board, curRow, curCol + 1, maxRow, maxCol);
        
        return;
    }
};