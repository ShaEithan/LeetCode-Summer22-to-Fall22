#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 08/29/2022 Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters; // set that contains our characters currently in our substring
        int windowStart = 0, windowEnd = 0, longestSubString = 0; 
        
        while (windowEnd < s.length()) { // we only need one pass, so once we get to the end we're done
            while (letters.find(s[windowEnd]) != letters.end()) { // we remove characters until we don't have any duplicates by sliding the beginning of our window forward
                letters.erase(s[windowStart]);
                windowStart++;
            }
            longestSubString = max (longestSubString, windowEnd - windowStart + 1); // recaluclate longest substring
            letters.insert(s[windowEnd]); // insert next character of the string
            windowEnd++; // slide windowEnd by one more index to get ready for next character
        }
        
        // O(N), O(1)
        return longestSubString;
    }
};