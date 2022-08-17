#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 08/16/2022 TopKFrequent (Medium) Arrays and Hashing Blind 75 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> myMap; // element, occurrences pair
        
        int arraySize = nums.size(); // size of our input array
        
        
        // add occurrences to our hashmap of that element
        for (int i = 0; i < arraySize; i++) {
            myMap[nums[i]]++;
        }
        
        vector<vector<int>> bucket(arraySize + 1); // size n + 1 to keep track of n occurences if all elements are the same
        
        // we are going to insert the elements at the index of the count of that
        // current element to help us return the k most frequent elements
        for (auto itr = myMap.begin(); itr != myMap.end(); itr++) {
            bucket[itr -> second].push_back(itr -> first);
        }
        
        // now we iterate through bucket to push that element into
        // our result vector until we have k elements
        
        // we start from the right side of the bucket, as the 
        // elements with most frequences will be at the end of the bucket
        
        // and we skip all the indexes that are empty 
        for (int i = arraySize; i > 0; i--) {
            
            // stop adding to result when we've reached the number of elements
            // returned
            if (result.size() >= k) {
                break;
            } 
            
            // insert into result, from right to left until 
            // we've reached the # we need as long as the bucket is empty
            if (!bucket[i].empty()) {
                result.insert(result.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        // Time Complexity: O(N), need O(N) time to traverse number array
        // need O(N) time to also traverse bucket vector of size N. O(N) + O(N) = O(N)
        // Space Complexity: O(N), need N arrays inside the array of array of ints
        return result;
    }
};