#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/19/2022 Longest Repeating Character Replacement (Medium) O(N)
    int characterReplacement(string s, int k) {
        vector<int> charCount(26); // initalize array of size 26 to keep track of count for each character
        
        int maxCount = 0, windowStart = 0, windowEnd = 0, result = 0;
        // maxCount is the number of occurrences for the most common character
        
        while (windowEnd < s.length()) { // sliding window
            charCount[s[windowEnd] - 'A']++; // slid window, add occurrence of current character
            maxCount = max(maxCount, charCount[s[windowEnd] - 'A']); // find if the current character is the most frequent character
            // so far in our substring
            
            // if the length of our array - count of most frequent character is greater than k
            // we need to shrink as we can't perform the operation more than k times
            if (windowEnd - windowStart + 1 - maxCount > k) {
                charCount[s[windowEnd] - 'A']--;
                windowStart++;
            }
            
            // find the max of our currentstring and current max string length
            result = max(result, windowEnd - windowStart + 1);
            windowEnd++;// slide window
        }
        
        return result;
    } 
};