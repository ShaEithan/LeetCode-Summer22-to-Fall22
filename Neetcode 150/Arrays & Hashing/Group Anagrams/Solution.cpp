#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result; // result vector
        
        unordered_map<string,vector<string>> anagramMap; // hashmap to store our key and string vector pairs
        
        
        
        for (int i = 0; i < strs.size(); i++) { // finding a key for each of the strings and then adding them to our hashmap
            string key = getKey(strs[i]); // call helper function to find a key for our string
            // if a key is already existing, that means there's already a string that is an anagram for a string in our hashmap
            
            anagramMap[key].push_back(strs[i]); // regardless if there's already a string existing for our current key,
            // we add our current string to a string vector according to our current key's string.
        }
        
        //  iterate through our hashmap and push all our "grouped" anagrams into our result array
        for (auto itr = anagramMap.begin(); itr != anagramMap.end(); itr++) {
            result.push_back(itr -> second);
        }
        
        return result;
    }
private:
    string getKey(string currentString) {
        vector <int> count(26); // initalize a vector of size 26, to store every letter of the alphabet 
        string myKey = ""; // string to return for our unique key
        // if a key we've already made exists, then our current string is an anagram of another string in the hashmap
        
        for (int j = 0; j < currentString.length(); j++) {
            count[currentString[j] - 'a']++; // subtract ascii value of a from our current character in our string to find the index of where our character is supposed to go in our count array
        }
        
        for (int k = 0; k < 26; k++) {
            myKey.append(to_string(count[k] + 'a')); // for every character, we add the value of a and turn it to a string to create our unique key
        }
        
        return myKey;
    }
};