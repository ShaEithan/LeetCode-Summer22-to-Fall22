#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
// Longest Consecutive Sequence (Medium) O(N), O(N)
    int longestConsecutive(vector<int>& nums) {
        // initialize a set for us to keep track of what numbers are in our array
        unordered_set<int> numSet(nums.begin(), nums.end()); // takes O(N) space 
        int result = 0; // variable that keeps track of current longest consequtive sequence 
        
        for (auto &currentNumber: numSet) { // iterating through our numberSet looking at the current Number
            
            if (!numSet.count(currentNumber - 1)) { // checking if our currentNumber has a left neighbor
            // if not then our current number is the start of a sequence
                int currentLength = 1;
                
                // if the next consecutive number in the sequence exists in our set, then
                // we continue incrementing the currentlength
                while (numSet.count(currentNumber + currentLength)) { // count is O(1) while .find is O(N)
                    currentLength++;
                }
                
                // check if our current sequence is longer than our current longest
                result = max(currentLength, result);
            }
        }
        
        return result;
    } 
};