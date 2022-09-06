#include <vector>
#include <string>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = ""; // initialize a result string to append to
        
        // go through every string in our array and append it, with the length of the current string and 
        // our special symbol # before it.
        for (int i = 0; i < strs.size(); i++) {
            string currentString = strs[i];
            result += to_string(currentString.size()) + "#" + strs[i];
        }
        
        return result; // return "encoded string"
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        vector<string> result; // vector to push our strings into after decoded
        
        int i = 0; // keeps track of the beginning of the next string
        
        while (i < s.length()) {
            int j = i; // begin iterating from i
            
            while (s[j] != '#') { // iterate j until we find our # sign. Telling us where the word will begin
                j++;
            }
            
            // find the length of our current substring starting at index i (starting point) with length
            // j - i as we iterated until we found a #
            int lengthCurrentString = stoi(s.substr(i, j - i));

            // our currentString begins at j + 1 because j is where our "#" is
            // and is the length of what we found earlier
            string currentString = s.substr(j + 1, lengthCurrentString);
            
            // push currentString into our result vector
            result.push_back(currentString);
            
            // reset i for the next string
            // j + 1 + lengthCurrentString will lead us to the string int of how long the next string is
            i = j + 1 + lengthCurrentString;
        }
        
        return result;
    }
};