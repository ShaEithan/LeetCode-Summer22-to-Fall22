#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 08/20/2022 Longest Substring without Repeating Characters (Medium) O(N), O(1)
    int lengthOfLongestSubstring(string s) {
        
        if (s.length() < 1) { // if the string is empty, then we just return 0
            return 0;
        }
        
        int windowStart = 0, windowEnd = 0, longestLength = 0; // initalizing our window indexes and longestLength
        unordered_set<char> myLetters; // set that keeps track of letters in our current substring
        
        while (windowEnd < s.length()) { // until we get to the end of the string
            
            if (myLetters.find(s[windowEnd]) != myLetters.end()) { // if we find a duplicate, then calculate current longest length
                longestLength = max(longestLength, windowEnd - windowStart); 
                
                while (myLetters.find(s[windowEnd]) != myLetters.end()) { // increment left window pointer, until the duplicate element only appears once
                    myLetters.erase(s[windowStart]);
                    windowStart++; 
                }
            } else { // if there isn't a duplicate, then we insert the next element into our set and expand window by one
                myLetters.insert(s[windowEnd]);
                windowEnd++;
            }
        }
        
        longestLength = max(longestLength, windowEnd - windowStart); // one last comparison to ensure we have the true longestlength
        return longestLength;
    }
};