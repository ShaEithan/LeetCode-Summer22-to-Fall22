#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/12/2022 Longest Repeating Character Replacement (Medium) O(N)
    int characterReplacement(string s, int k) {
        vector<int> characters(26); // initialize integer array of size 26 to keep track of occurrences
        // of each letter. We only need 26 because all letters are uppercase
        
        int windowStart = 0, windowEnd = 0, maxFrequency = 0, result = 0;
        
        // iterate until we reach the end of the string 
        while (windowEnd < s.length()) {
            characters[s[windowEnd] - 'A']++; // after we slide our window increment the count of our certain letter
            
            maxFrequency = max(maxFrequency, characters[s[windowEnd] - 'A']); // find the maximum frequency of that
            // current character
            
            // if our window is large and has greater than k frequency for a certain character
            // then shrink your window 
            if (windowEnd - windowStart + 1 - maxFrequency > k) {
                characters[s[windowStart]]--;
                windowStart++;
            }
            
            // compare current length of string vs our current longest
            // there's a + 1 because C++ is 0 indexed 
            result = max(result, windowEnd - windowStart + 1);
            windowEnd++;
        }
        
        return result;
    }
};