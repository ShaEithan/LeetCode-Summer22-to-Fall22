#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,bool> my_map;
        
        for (int i = 0; i < nums.size(); i++){
            if (my_map[nums[i]]){
                return true;
            }
            my_map[nums[i]] = true;
        }
        
        return false;
    }
};