#include <string>
#include <unordered_set>

using namespace std;

// 09/05/2022
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0, windowEnd = 0, longestLength = 0;
        
        unordered_set<char> currentLetters;
        
        while (windowEnd < s.length()) {
            
            while (currentLetters.find(s[windowEnd]) != currentLetters.end()) {
                currentLetters.erase(s[windowStart]);
                windowStart++;
            }
            
            longestLength = max(windowEnd - windowStart + 1, longestLength);
            currentLetters.insert(s[windowEnd]);
            windowEnd++;
        }
        
        return longestLength;
    }
};