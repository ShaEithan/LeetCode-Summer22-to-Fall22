#include <vector>

using namespace std;

class Solution {
public:
    // 57. Insert Interval (Medium) Intervals
    
    // Time Complexity: O(N), need to iterate over N intervals
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        
        // add all intervals that exist before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // when we get to this point, there will be overlap, so we need to merge that
        // for all intervals ahead that have overlap
        // this keeps track of all intervals that occur before the end of the new intervals end
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        
        // push the merged interval into our result;
        result.push_back(newInterval);
        // if there are any remaining intervals after our merged time, we need to append them as well
        
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};