#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/20/2022 Group Anagrams (Medium) O(N * M), O(N) space 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result; // result vector 
        unordered_map<string, vector<string>> keyToGroup; // map to keep track of key group pairs
        
        for (int i = 0; i < strs.size(); i++) { // find current key, then append the current string to the vector
            // mapped to the key O(N) for the number of strings in our strs array
            string currentKey = findKey(strs[i]);
            keyToGroup[currentKey].push_back(strs[i]);
        }
        
        // push each group into our result when iterating through the hashmap
        for (auto itr = keyToGroup.begin(); itr != keyToGroup.end(); itr++) { // O(N) at most, if every word is different
            result.push_back(itr -> second);
        }
        
        return result;
    }
    string findKey(string currentString) {
        string key = ""; // key to append to
        vector<int> charCount(26); //array to keep track of the counts of each character
        // if a string is an anagram, then they should have the same amount of occurrences for all digits
        
        // count occurences and place them at index of their character by subtracting the ascii value
        for (int i = 0; i < currentString.length(); i++) { // O(M) size of string
            charCount[currentString[i] - 'a']++;
        }
        
        // turn occurences of a character into a string and append it to our generated key
        for (int i = 0; i < charCount.size(); i++) { // 0(26)
            key += to_string(charCount[i] + 'a');
        }
        
        return key;
    }
};