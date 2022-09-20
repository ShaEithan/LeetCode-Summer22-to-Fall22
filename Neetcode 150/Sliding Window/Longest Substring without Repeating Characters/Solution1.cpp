#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// 07/29/2022 Longest SubString without repeating characters

// Time Complexity: O(N), need to do only one pass of the array
// Space Complexity: O(N), if there are no repeating characters, then
// we'd have N unique characters in our set


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // unordered set to keep track of our current substring
        unordered_set<char> letters;
        
        int i = 0; // windowStart pointer
        int j = 0; // windowEnd poinnter
        
        int result = 0;
        
        // iterate until we reach the end of the string
        while (j < s.size()) {
            
            // if there isn't a duplicate letter then we insert the 
            // next unique character in the set
            
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                
                // reassign the result comparing the current length of our window
                // and the current longest substring length
                result = max(result, j - i + 1);
                j++; // increment our right pointer to grow our window
            } else {
                letters.erase(s[i]); // we have a duplicate so we remove it from ourr set
                i++; // and increment our left pointer to shrink the window
            }
        }
        
        return result;
    }
};