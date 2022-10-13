#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 10/12/2022 Parallel Courses (Hard)
    // Time Complexity: O(N + M) N = # of courses M = # of edges
    // Space Complexity: O(N + M) 
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n);
        vector<vector<int>> myGraph(n, vector<int>());
        
        for (auto & curEdge : relations) {
            int pre = curEdge[0] - 1;
            int nextCourse = curEdge[1] - 1;
            myGraph[pre].push_back(nextCourse);
            inDegree[nextCourse]++;
        }
        
        vector<int> distance(n); // keeps track of distance / time 
        queue<int> classQ; // queue that pushes courses in the order we want to take them
        
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                classQ.push(i);
                distance[i] = time[i];
            }
        }
        
        while (!classQ.empty()) {
            int current = classQ.front();
            classQ.pop();
            
            for (int course : myGraph[current]) {
                distance[course] = max(distance[course], distance[current] + time[course]);
                // update dist[course] using maximum distance of predecessor nodes
                
                // if we don't have anymore preReqs for this particular course
                // then we push it into the queue to work with it
                if (--inDegree[course] == 0) {
                    classQ.push(course);
                }
            }
        }
        // we want the minimum amount of months needed to complete all courses
        // so we return the max element from our distance array
        int months = *max_element(distance.begin(), distance.end());
        
        return months;
    }
};