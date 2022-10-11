#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 10/10/2022 Longest Repeating Char Replacement (Medium) 
    // Time Complexity: O(N), only need to traverse over string once
    // Space Complexity: O(N), could have N unique characters to keep track of 
    
    int characterReplacement(string s, int k) {
        // Assumption: We need to keep track of the
        // count of the max frequent character
        
        // This is because to make the longest repeating
        // character replacement, we need a count of <= K
        // characters of that element, otherwise we can't
        // make the character replacement any longer
        
        unordered_map<char,int> charMap;
        
        // use sliding window to iterate through the 
        // string
        
        // initialize window, stringLength, result
        // and maxCount variables
        int left = 0, right = 0, stringLength = s.length(), result = 0, maxCount = 0;
        
        while (right < stringLength) {
            // find maxCount and slide the window and add frequency
            charMap[s[right]]++;
            maxCount = max(maxCount, charMap[s[right]]);
            
            // check if we need to shrink the window
            // because we can't replace enough elements
            if (right - left + 1 - maxCount > k) {
                charMap[s[left]]--;
                left++;
            }
            
            // lets check if we have a new longest length value
            if (right - left + 1 > result) {
                result = right - left + 1;
            }
            right++;
        }
        
        return result;
    }
};