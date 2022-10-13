#include <vector>

using namespace std;

class Solution {
public:
    // 10/12/2022 Surrounded Regions (Medium)

    void solve(vector<vector<char>>& board) {
        int maxRows = board.size(), maxCols = board[0].size();
        
        // do DFS from edges
        
        // up and down (top row and bottom row)
        for (int i = 0; i < maxRows; i++) {
            dfs(board, maxRows, maxCols, i, 0);
            dfs(board, maxRows, maxCols, i, maxCols -1);
        }
        
        // left to right to mark unsurrounded
        for (int j = 0; j < maxCols; j++) {
            dfs(board, maxRows, maxCols, 0, j);
            dfs(board, maxRows, maxCols, maxRows - 1, j);
        }
        
        // iterate through the board
        
        for (int i = 0; i < maxRows; i++) {
            for (int j = 0; j < maxCols; j++) {
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
    
    void dfs(vector<vector<char>> &board, int maxRow, int maxCol, int curRow, int curCol) {
        // check if we're in bounds
        // and if the element is an 'O'
        
        if (curRow < 0 || curCol < 0 || curRow >= maxRow || curCol >= maxCol || board[curRow][curCol] != 'O') {
            return;
        }
        
        // mark the current part as visited
        board[curRow][curCol] = 'E';
        
        // do DFS on all 4 directions
        dfs(board, maxRow, maxCol, curRow - 1, curCol);
        dfs(board, maxRow, maxCol, curRow + 1, curCol);
        dfs(board, maxRow, maxCol, curRow, curCol - 1);
        dfs(board, maxRow, maxCol, curRow, curCol + 1);
        
        return;
    }
};