#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> CharCount(26); // array to keep track of occurences for each letter
        
        int maxCount = 0; // max frequency, so we don't have to access the entire array
        // to find the maxCount everytime
        
        // initalizing our window and our result (length of longest repeating character replacement)
        int windowStart = 0, windowEnd = 0, result = 0;
        
        while (windowEnd < s.length()) {
            // after we've slid our window, we add the newest element's occurence to our count array
            CharCount[s[windowEnd] - 'A']++;

            // find the max frequency, meaning that we fin
            maxCount = max(maxCount, CharCount[s[windowEnd] - 'A']);
            
            // check if we meet our condition that our window length - count of current char at windowEnd < K
            // if not, we slide the beginning of our window forward and remove occurence of slid over element
            if (windowEnd - windowStart + 1 - maxCount > k) {
                CharCount[s[windowStart] - 'A']--;
                windowStart++;
            }
            
            // find the longest length of substring to return, either a previous window had a longer length
            // or our current window is the longest. We use + 1 because C++ is 0 indexed
            result = max(result, windowEnd - windowStart + 1);
            
            // slide window over 1 (expand)
            windowEnd++;
        }
        
        // Time Complexity: O(N), need one pass over the entire string
    
        return result;
    }
};