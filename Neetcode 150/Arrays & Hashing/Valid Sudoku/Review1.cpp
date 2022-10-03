#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 10/01/2022 Valid Sudoku (Medium)
    // Time Complexity: O(n^2) as we need to iterate through n^2 elements in the board

    bool isValidSudoku(vector<vector<char>>& board) {
        int dimension = 9;
        vector<unordered_set<char>> rows(dimension);
        vector<unordered_set<char>> cols(dimension);
        vector<unordered_set<char>> squares(dimension);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                
                if (rows[i].find(board[i][j]) != rows[i].end()) {
                    return false;
                }
                
                rows[i].insert(board[i][j]);
                
                if (cols[j].find(board[i][j]) != rows[j].end()) {
                    return false;
                }
                
                cols[j].insert(board[i][j]);
                
                int square = (i / 3) * 3 + (j / 3);
                
                if (squares[square].find(board[i][j]) != squares[square].end()) {
                    return false;
                }
                
                squares[square].insert(board[i][j]);
            }
        }
        
        return true;
    }
};