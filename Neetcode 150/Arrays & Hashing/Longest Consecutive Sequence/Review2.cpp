#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
// there's a faster solution that instead of interating through the array
// we iterate through the set by accessing each element and then
// doing the count functions

    // 09/20/2022 Longest Consecutive Sequence O(N), O(N) 
    int longestConsecutive(vector<int>& nums) {
        int result = 0; // keep track of longest sequence length
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int length = 1, currentNum = nums[i];
            
            if (numSet.count(currentNum - 1)) { // if the currentNumber is not the start of a sequence keep going 
                continue;
            }
            
            while (numSet.count(currentNum + length)) { // increment length as long as the next consecutive number exists
                length++;
            }
            
            result = max(result, length); // compare our current length to current max
        }
        
        return result;
    }
};