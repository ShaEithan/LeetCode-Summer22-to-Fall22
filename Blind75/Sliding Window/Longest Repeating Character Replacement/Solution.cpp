#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> CharCount(26);
        
        int maxCount = 0;
        
        int windowStart = 0, windowEnd = 0, result = 0;
        
        while (windowEnd < s.length()) {
            CharCount[s[windowEnd] - 'A']++;
            maxCount = max(maxCount, CharCount[s[windowEnd] - 'A']);
            
            if (windowEnd - windowStart + 1 - maxCount > k) {
                CharCount[s[windowStart] - 'A']--;
                windowStart++;
            }
            
            result = max(result, windowEnd - windowStart + 1);
            
            windowEnd++;
        }
        
        return result;
    }
};