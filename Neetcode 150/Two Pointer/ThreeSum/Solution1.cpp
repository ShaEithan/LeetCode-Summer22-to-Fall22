#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(N^2), sort in O(nlogn) + doing operations on N elements, and iterating N times for each of those N elements
    // O(N^2) nlogn + n^2 = n^2
    
    // Space Complexity: O(1) or O(n), depends on language

    vector<vector<int>> threeSum(vector<int>& nums) {
        // initalize a vector to store our triplets
        vector<vector<int>> result;
        
        int n = nums.size(); // get the number of elements in our numbers array
        
        if (n < 3) { // edge case: if we have less than 3 entries just return our empty vector
            return result;
        }
        
        // step 1: sort the input array so we can handle and pass over duplicates
        sort(nums.begin(), nums.end()); // O(nlogn)
        
        // iterate through array to find our first value and calculate the currentSum based
        // on the next two values O(N)
        for (int firstNum = 0; firstNum < n - 2; firstNum++) {
            // every iteration of this for, makes our first number to add
            // a non duplicate and lets us calculate a new combo of triplet
            if (nums[firstNum] > 0) {
                break;
            }
            
            // if we find a duplicate of our current first value to add
            // go to the next number
            if (firstNum > 0 && nums[firstNum - 1] == nums[firstNum]) {
                continue;
            }
            
            // after this we've found our first value to add 
            // now we're going to use two pointers
            
            int left2 = firstNum + 1;
            int right3 = nums.size() - 1;
            
            // solve like two sum II, use 2 pointers and traversse left and right pointers
            // depending on if the currentsum is greater or smaller than 0.
            // if sum adds to 0, then we push into our result vector
            int currentSum;
            
            
            while (left2 < right3) {

                // find currentSum 
                
                currentSum = nums[firstNum] + nums[left2] + nums[right3];
                
                if (currentSum < 0) { // if currentSum < 0, then we need a bigger sum, so we increment left pointer
                    left2++;
                } else if (currentSum > 0) { // if currentSum > 0, need a smaller sum, so we deinc. right pointer
                    right3--;
                } else { // this is where currentsum = 0, what we're looking for
                    
                    result.push_back({nums[firstNum], nums[left2], nums[right3]}); // push triplet into our result vector
                    
                    while (left2 < right3 && nums[left2] == nums[left2 + 1]) { // make sure left pointer doesn't have 2 duplicates in a row
                        left2++;
                    }
                    left2++; // moves from duplicate to a new value
                    
                    while (left2 < right3 && nums[right3 - 1] == nums[right3]) { // make sure right pointer doens't have 2 duplicates in a row
                        right3--;
                    }
                    right3--; // move from duplicate to new value
                }
                
            }
        }
        
        return result; // return result vector
    }
};