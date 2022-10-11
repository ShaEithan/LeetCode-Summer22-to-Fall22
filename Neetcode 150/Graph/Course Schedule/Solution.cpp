#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 10/10/2022 Course Schedule (Medium) Adjacency List DFS
    
    // Time Complexity: O(N + P), N = # of courses, P = # of prereqs
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // use a hashmap and a set to keep track of courses (and prereqs) and 
        // what courses we can visit
        unordered_set<int> visited;
        unordered_map<int,vector<int>> preMap;
        
        // map courses to their prereqs
        // course, prereq key value pair
        for (int i = 0; i < prerequisites.size(); i++) {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // do DFS traversal on all courses
        // if we find a course that has a loop, or we can't reach
        // then return false
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preMap, visited)) {
                return false;
            }
        }
        
        return true;
    }
    bool dfs(int curCourse, unordered_map<int, vector<int>> &preMap, unordered_set<int> &visited) {
        if (visited.find(curCourse) != visited.end()) { // if we find it in the visited, that means that there's a loop
            return false;
        }
        
        if (preMap[curCourse].empty()) { // if the pre req array of the current course is empty, return true
            return true; // this means that we have all the classes needed to complete the class
        } 
        
        visited.insert(curCourse); // mark course as visited
        
        // run DFS again on the remaining prerequisites
        for (int i = 0; i < preMap[curCourse].size(); i++) {
            int nextCourse = preMap[curCourse][i];
            if (!dfs(nextCourse, preMap, visited)) {
                return false;
            }
        }
        
        // if we get to this point, we need to clear our pre reqs for this current course
        // and erase it from visited because we can confirm that this course can be completed
        preMap[curCourse].clear();
        visited.erase(curCourse);
        
        return true;
    }
};