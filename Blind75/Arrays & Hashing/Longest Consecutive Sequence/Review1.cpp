#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        
        unordered_set<int> numbers(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int length = 1;
            
            if (!numbers.count(nums[i] - 1)) {
                int currentNumber = nums[i];
                
                while (numbers.count(currentNumber + length)) {
                    length++;
                }
                
                longest = max(longest,length);
            }
        }
        
        return longest;
    }
};