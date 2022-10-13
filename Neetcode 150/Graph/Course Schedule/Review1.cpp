#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 10/12/2022 Course Schedule (Medium) 
    
    // Time Complexity: O(N + P) where N is the # of nodes and p = # of preReqs (edges)
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        unordered_set<int> visited; 
        
        // map prereqs and courses together
        for (int i = 0; i < prerequisites.size(); i++) {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // run DFS on all courses from 0 to numCourses - 1
        // DFS is going to return a bool, tells us if we can take
        // all the classes from that class
        
        // if not return false
        for (int i = 0; i < numCourses; i++) {
            bool canTake = dfs(preMap, visited, i);
            if (!canTake) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>> &preMap, unordered_set<int> &visited, int curCourse) {
        // check if there's a cycle
        // check our visited set, if our current course already exists in it then return false
        if (visited.find(curCourse) != visited.end()) {
            return false;
        }
        // check if the prereqs for the current course are empty
        if (preMap[curCourse].empty()) {
            return true;
        }
        // mark course as visited
        visited.insert(curCourse);
        
        // iterate through the current courses prerequisite array in the mapand run DFS on those
        
        for (int i = 0; i < preMap[curCourse].size(); i++) {
            // check if those other courses in the preReqs of our current course are also true/possible
            bool canTake = dfs(preMap, visited, preMap[curCourse][i]);
            if (!canTake) {
                return false;
            }
        }
        
        // when we make it to this point, then we can consider that this course is possible to be taken
        // in order to mark this, we clear the pre reqs for this course and remove our course from visited
        
        visited.erase(curCourse);
        preMap[curCourse].clear();
        
        return true;
    }
};