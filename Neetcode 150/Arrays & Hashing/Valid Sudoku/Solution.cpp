#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // 09/28/2022 Valid Sudoku (Medium)
    
    // Time Complexity: O(n^2), need to iterate through all elements of the board
    // Space Complexity: O(n^2), if board is complete, then we need n^2 space for all unique elements
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = 9; // dimension of board
        
        // initialize arrays of size of the board with type hashSet, so we can keep track of all 9 rows and columns and their
        // values we've already iterated over
        vector<unordered_set<int>> rows(size);
        vector<unordered_set<int>> columns(size);
        
        // we create an array of sets for each square as well to keep track of what elements are in each square
        vector<unordered_set<int>> squares(size);
        
        // iterate through all elements of the board
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == '.') { // if the char is this then we continue
                    continue;
                }
                
                if (rows[i].find(board[i][j]) != rows[i].end()) { // if the current element already exists for the current rows
                    return false; // return false not valid
                }
                
                rows[i].insert(board[i][j]); // if no duplicate, insert into our current rows set
                
                if (columns[j].find(board[i][j]) != columns[j].end()) { // if the current element already exists in the current column
                    return false; // not valid
                }
                
                columns[j].insert(board[i][j]); // otherwise insert current element into our current Columns set
                
                int squareNum = (i / 3) * 3 + (j / 3); // find which square our current element is in
                // taking current row / 3 * 3 + current column / 3
                
                if (squares[squareNum].find(board[i][j]) != squares[squareNum].end()) {
                    return false; // if already exists in square, not valid
                }
                
                squares[squareNum].insert(board[i][j]);
            }
        }
        
        
        return true;
    }
};