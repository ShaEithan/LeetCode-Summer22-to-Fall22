#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // 239. Sliding Window Maximum (Hard) Self Attempt 1 O(N), O(N)
    // Incomplete
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if (nums.size() < k) {
            return {};
        } else if (k == 1) {
            return nums;
        }
        
        int windowStart = 0, windowEnd = 0;
        vector<int> result;
        unordered_set<int> windowSet;
            
        while (windowEnd < nums.size()) {
            
            while (windowEnd - windowStart < k) {
                windowSet.insert(nums[windowEnd]);
                windowEnd++;
            }
            
            int currentMax = INT_MIN;
            for (auto itr = windowSet.begin(); itr != windowSet.end(); itr++) {
                currentMax = max(currentMax, *itr);
            }
            result.push_back(currentMax);
            
            windowSet.erase(nums[windowStart]);
            windowStart++;
        }
        
        return result;
    }
};