#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    // Group Anagrams (Medium) O(N * M) O(N) 08/28/2022
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result; // result vector
        unordered_map<string, vector<string>> anagramMap; // hashmap to store our information in 
        
        for (int i = 0; i < strs.size(); i++) { // O(N), iterate over N elements, and find a key for each one and at our key, push our current string into it's vector
            string currentString = strs[i];
            
            string key = findKey(currentString); // O(N*M) N strings * M characters in each string
            
            anagramMap[key].push_back(currentString);
        }
        
        for (auto itr = anagramMap.begin(); itr != anagramMap.end(); itr++) { // O(N) iterate over hashmap and push vectors into our result array
            result.push_back(itr -> second);
        }
        
        return result;
    }
private:
    string findKey(string currentString) {
        vector<int> letters(26,0); // initalize vector of size 26 for all lower case letters 
        string key = ""; // string to append to and return for our unique key
        
        for (int i = 0; i < currentString.length(); i++) { // O(M)  M + # of characters in the string
            int index = currentString[i] - 'a'; // subtract ascii value of 'a' to find the index of our current letter
            
            letters[index]++; // at that index of our letter increment by 1 to show one more occruence
        }
        
        for (int i = 0; i < 26; i++) { // O(26)
            key += to_string(letters[i] + 'a'); // iterate over letter array and add back value 'a' and turn it into a string to generate our unique key
        }
        
        return key; 
    }
};