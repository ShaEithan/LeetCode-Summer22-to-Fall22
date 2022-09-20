#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> anagramMap;
        vector<vector<string>> result;
            
        for (int i = 0; i < strs.size(); i++) {
            string currentKey = findKey(strs[i]);
            
            anagramMap[currentKey].push_back(strs[i]);
        }
        
        for (auto itr = anagramMap.begin(); itr != anagramMap.end(); itr++) {
            result.push_back(itr -> second);
        }
        
        return result;
    }
    
private:
    string findKey(string currentString) {
        string myKey = "";
        vector<int> countArray(26);
        
        for (int i = 0 ; i < currentString.length(); i++) {
            int index = currentString[i] - 'a';
            countArray[index]++;
        }
        
        for (int i = 0; i < 26; i++) {
            string temp = to_string(countArray[i] + 'a');
            myKey.append(temp);
        }
        
        return myKey;
    }
};