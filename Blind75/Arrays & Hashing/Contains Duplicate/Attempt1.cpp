#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // 5/28/2022
        // Using a hashmap to check occurences of unique numbers
        // Access Time for hashmap is O(1)
        // key pair is number, # of instances this number appears
        
        unordered_map<int,int> my_map;
        
        for (int i = 0; i < nums.size(); i++)
        {
            // if this key has already appeared in our hashmap
            // then we know we have a duplicate
            if (my_map[nums[i]] == 1)
            {
                return true; // there are duplicates
            }
            
            // if it hasn't already appeared, we insert it into our hashmap
            my_map[nums[i]] = 1;
        }
        
        return false; // no duplicates
        
        // Time Complexity: O(N), we need to traverse and check over N possible
        // unique integers
        // Space Complexity: O(N), worst case, all n values are unique, so we 
        // need to have space for n values.
    }
};