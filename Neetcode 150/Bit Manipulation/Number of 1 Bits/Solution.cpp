#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // 191. # of 1 Bits (Easy) Bit Manipulation
    int hammingWeight(uint32_t n) {
        // Approach: Iterating bit by bit and counting the number of 1's
        int result = 0; // number of 1 bits
        int currentBit = 0; // identifies our current bit 
        
        while (n != 0) { // iterate until we get to the end of our input
            currentBit = n & 1; // using logical & to get our current Bit
            
            if (currentBit == 1) { // if it's a 1 increment
                result++;
            }
            
            n = n >> 1; // otherwise use bitshift operator >> to move to the next bit 
        }
        
        // Time Complexity: O(1), operations never grow, always the size of the input
        // Space Complexity: O(1), constant space 
        return result;
    }
};