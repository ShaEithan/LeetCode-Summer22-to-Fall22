#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.length() == 0) {
            return 0;
        }
        
        int result = 0;
        int windowStart = 0, windowEnd = 0;
        
        unordered_set<char> mySet;
        
        while (windowEnd < s.length()) {
            
            if (mySet.find(s[windowEnd]) != mySet.end()) { // duplicate character
                mySet.erase(s[windowStart]);
                windowStart++; 
            } else { // no duplicate found 
                result = max (result, windowEnd - windowStart + 1);
                mySet.insert(s[windowEnd]);
                windowEnd++;
            }
        }
        
        return result;
    }
};