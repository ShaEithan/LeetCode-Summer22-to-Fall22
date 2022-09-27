#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 09/26/2022 
    
    // Time Complexity: O(N), as we only need one pass of the string
    // Space Complexity: O(N), need N elements of space, if all characters are unique
    int characterReplacement(string s, int k) {
        int result = 0; // variable to keep track of longest substring length
        unordered_map<char,int> countMap; // keep track of occurrences of characters in the string
        
        int windowStart = 0, windowEnd = 0, maxCount = 0; // initialize window pointers and the maximum count of a character
        
        while (windowEnd < s.length()) { // O(N), only one pass of the string
            countMap[s[windowEnd]]++; // add occurrence to map
            maxCount = max(maxCount, countMap[s[windowEnd]]); // keeps track of most frequent character occurrences
            
            if (windowEnd - windowStart + 1 - maxCount > k) { // if the length - maxCount > k, means we need to do more than k operations
                // to make the character replacement repeating so we need to shrink the window forward.
                countMap[s[windowStart]]--;
                windowStart++;
            }
            
            result = max(windowEnd - windowStart + 1, result); // find max length
            windowEnd++;
        }
        
        return result;
    }
};