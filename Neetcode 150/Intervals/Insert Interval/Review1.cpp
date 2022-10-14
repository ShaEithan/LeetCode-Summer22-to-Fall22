#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int i = 0, n = intervals.size();
        
        // add all intervals that exist before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // after we add all before our newInterval, there will be overlap
        // so we need to merge the newInterval to make sure there isn't any overlap anymore
        
        // while we're in bounds and the start of the current interval is less than or equal to 
        // the new interval
        // adjust bounds of ner interval depending on current interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
            i++; // after changing bounds when comparing current interval, increment
        }
        
        // we then append our new adjusted new interval to our result
        result.push_back(newInterval);
        
        // then we append all intervals that occur after our adjusted new one to the result
        
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};