#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 09/26/2022
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        vector<int> result;
        int numsSize = nums.size();
        
        for (int i = 0; i < numsSize; i++) { // O(N) one pass
            numMap[nums[i]]++;
        }
                   
        vector<vector<int>> bucket(numsSize + 1); // + 1 because there are that many occurrences and C++ is 0 indexed
        
        // O(N) one pass 
        for (auto itr = numMap.begin(); itr != numMap.end(); itr++) { // insert elements of frequency i at index i
            bucket[itr -> second].push_back(itr -> first); // inserting elements at the index of their frequency
        }
        
        // O(N) one pass of the array at worst
        for (int i = numsSize; i > 0; i--) { // iterate right to left, as we 
            if (result.size() >= k) { // if we've reached capacity then we're good
                break;
            }
            
            if (!bucket[i].empty()) { // push all elements of the bucket of that occurrence into the result
                result.insert(result.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        // Time Complexity: O(N), 3 passes of N elements at worst 
        // Space Complexity: O(N), could have N unique 
    }
};