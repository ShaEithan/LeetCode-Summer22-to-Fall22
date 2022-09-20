#include <vector>

using namespace std;

class Solution {
public:
    // 48. Rotate Image (Medium) O(N^2), O(1)
    void rotate(vector<vector<int>>& matrix) {
        int matrixSize = matrix.size(); // # of rows or columns
        
        // iterating through the entire matrix
        for (int currentRow = 0; currentRow < matrixSize; currentRow++) {
            for (int currentColumn = currentRow; currentColumn < matrixSize; currentColumn++) {
                swap(matrix[currentRow][currentColumn], matrix[currentColumn][currentRow]);
                // we swap the row and column of an element to the opposite side (transpose or flip)
            }
            
            // then at that row, reverse it from left to right
            reverse(matrix[currentRow].begin(), matrix[currentRow].end());
        }
        
        return;
    }
};