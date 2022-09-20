#include <vector>
#include <string>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            int stringLength = strs[i].length();
            result += to_string(stringLength) + "#" + strs[i];
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        
        while (i < s.length()) {
            int j = i; // i is our starting index, j is a pointer we're going to use to find where our unique character is 
            
            while (s[j] != '#') { // iterate until we find our unique character
                j++;
            }
            
            int stringLength = stoi(s.substr(i, j - i)); // the j - i is the length of the string
            // we're turning into an integer that we defined as our string length in encode
            
            string currentString = s.substr(j + 1, stringLength); // starting index is j + 1, because our string
            // starts after our unique character
            result.push_back(currentString); // push our string into our result
            
            i = j + 1 + stringLength; // reset i to start at the first number of our next string length
        }
        
        return result;
    }
};