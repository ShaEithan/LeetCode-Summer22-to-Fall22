#include <vector>
#include <string>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            string lengthString = to_string(strs[i].length());
            result += lengthString + "#" + strs[i];
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0; 
        
        while (i < s.length()) {
            int j = i; // pointer that we iterate to tell us where the end of our string length is and where our string actually begins
            
            // 6#eithan
            while (s[j] != '#') { // once this pointer finds #, that's where the end of our length of the current string is 
                j++;
            }
            
            int lengthOfString = stoi(s.substr(i, j - i)); // turns the length we appended into an int 
            
            string currentString = s.substr(j + 1, lengthOfString); // starting at j + 1 (index of first character in current string) and
            //  with a length of LengthOfString characters
            
            result.push_back(currentString); // push our currentString into our result array
            
            i = j + 1 + lengthOfString; // j is currently on the "#" string, so we reset i so that we can find the next length of our next string
        }
        return result;
    }
    
    // Time Complexity: O(N), N being the # of characters total in the string, just doing 2 passes over the total number of characters 
    // Space Complexity: O(1)
};