#include <vector>
#include <string>

using namespace std;

class Codec {
public:
    // 10/01/2022 Encode and Decode Strings (Medium) 
    // Time Complexity O(N + M) where N is the number of strings in array strs and M is the number of characters
    // in the encoded string
    // Space Complexity: O(N), where N is the # of strings in our array strs
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) { // O(N) 
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            
            result += to_string(strs[i].length()) + "#" + strs[i];
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result; // result vector
        
        int left = 0; // left pointer
        
        while (left < s.length()) {  // we know that we're at the end of the string when we've gotten to the end of our encoded string
            int right = left;
            
            while (s[right] != '#') { // traverse right to #, so we know the length of the string
                right++; // and can turn it into an integer
            }
            
            int stringLength = stoi(s.substr(left, right - left));
            string currentString = s.substr(right + 1, stringLength);
            result.push_back(currentString);
            
            left = right + stringLength + 1; // reset left pointer to begin at the first digit of the next string length
        }
        
        return result;
    }
};