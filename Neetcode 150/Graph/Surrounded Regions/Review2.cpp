#include <vector>

using namespace std;

class Solution {
public:
    // 10/06/2022 Surrounded Regions (Medium)
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        
        // do dfs to find unsurrounded regions of 'O's
        // we make all unsurrounded 'O's a unique character so we can 
        // convert later
        
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0, rows, cols); // left most column
            dfs(board, i, cols - 1, rows, cols); // right most column
        }
        
        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j, rows, cols); // upperleft most element (first row)
            dfs(board, rows - 1, j, rows, cols); // starting from bottom row
        }
        
        // iterate over board to convert characters accordingly
        for (int i = 0; i < rows; i++) {
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
        // doing dfs to find unsurrounded regions of '0's
        
        // make sure we're in bounds and that it's the character we want to change
        if (curRow < 0 || curCol < 0 || curRow >= maxRow || curCol >= maxCol || board[curRow][curCol] != 'O') {
            return;
        }
        
        // mark element as unique character bc this is unsurrounded
        board[curRow][curCol] = 'E';
        
        // do DFS on all adjacent directions
        dfs(board, curRow - 1, curCol, maxRow, maxCol);
        dfs(board, curRow + 1, curCol, maxRow, maxCol);
        dfs(board, curRow, curCol - 1, maxRow, maxCol);
        dfs(board, curRow, curCol + 1, maxRow, maxCol);
        
        return;
    }
};