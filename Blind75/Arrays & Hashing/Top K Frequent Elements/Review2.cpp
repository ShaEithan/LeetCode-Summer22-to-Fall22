#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// 09/05/2022
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        
        unordered_map<int,int> countMap;
        
        for (int i = 0; i < nums.size(); i++) {
            countMap[nums[i]]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        
        for (auto itr = countMap.begin(); itr != countMap.end(); itr++) {
            bucket[itr -> second].push_back(itr -> first);
        }
        
        for (int i = nums.size(); i > 0; i--) {
            if (answer.size() >= k) {
                break;
            }
            
            if (!bucket[i].empty()) {
                answer.insert(answer.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        return answer;
    }
};