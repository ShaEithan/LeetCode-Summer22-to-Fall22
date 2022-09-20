#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 08/28/2022 Top K Frequent Elements (Medium) O(N) O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        
        if (nums.empty()) { // if there are no elements return a empty result vector
            return result;
        }
        
        unordered_map<int,int> myMap; // hashmap to store our information
        
        for (int i = 0; i < nums.size(); i++) { // O(N)
            myMap[nums[i]]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1); // use a vector vector int because there may be elements that occur the same # of times
        
        // insert the element itself at the index of how many occurences there are of tht element
        
        for (auto itr = myMap.begin(); itr != myMap.end(); itr++) { // O(N)
            bucket[itr -> second].push_back(itr -> first);
            // this lets us have most frequent elements on the right side of the array
        }
        
        for (int i = nums.size(); i > 0; i--) { // O(N) // iterate from right to left as most frequent is at the right
            if (result.size() >= k) {
                break; // once we have the required number of elements stop adding
            }
            
            if (!bucket[i].empty()) {
                result.insert(result.end(), bucket[i].begin(), bucket[i].end()); 
                // insert into our result vector all elements of the vector<int> inside bucket at that index
            }
        }
        return result;
    }
};