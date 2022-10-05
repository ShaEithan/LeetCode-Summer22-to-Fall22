#include <vector>

using namespace std;

class Solution {
public:
    // 10/05/2022 Surrounded Regions (Medium)
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) 
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        
        // begin finding all unsurrounded 'O's
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0, rows, cols); // start from left most column
            dfs(board, i, cols - 1, rows, cols); // start from rightmost column
        }
        
        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j, rows, cols); // start from top
            dfs(board, rows - 1, j, rows, cols); // start from bottom
        }
        
        // iterate through board and convert characters depending on what the current element is 
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
        // make sure we're inbounds and that we're changing only Os 
        if (curRow < 0 || curCol < 0 || curRow >= maxRow || curCol >= maxCol || board[curRow][curCol] != 'O') {
            return;
        }
        
        // mark as visited / unsurrounded
        board[curRow][curCol] = 'E';
        
        // do dfs on 4 directions
        dfs(board, curRow - 1, curCol, maxRow, maxCol);
        dfs(board, curRow + 1, curCol, maxRow, maxCol);
        dfs(board, curRow, curCol - 1, maxRow, maxCol);
        dfs(board, curRow, curCol + 1, maxRow, maxCol);
        return;
    }
};