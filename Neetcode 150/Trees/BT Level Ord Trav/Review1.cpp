#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 08/24/2022 BT Level Order Traversal (Medium) 
    // Time Complexity: O(N), need to traverse over N nodes
    // Space Complexity: O(N/2) -> O(N), as at one time we'd have N/2 nodes in our queue
    // once we've hit the last level of our tree
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // vector to return level order traversal 
        // Use Tree BFS and a queue because we need level order traversal
        vector<vector<int>> result;
        
        if (root == nullptr) { // if we don't have a tree to traverse, then we return a empty array
            return result;
        }
        
        queue<TreeNode*> myQueue; // array for BFS
        
        myQueue.push(root); // begin traversal by pushing our root
        
        while (!myQueue.empty()) { 
            int currentLevelSize = myQueue.size(); // the size of the queue at this time, is the 
            // number of nodes on the current level
            vector<int> currentLevel; // array to push values into, so that we can keep track of
            // what nodes we traversed
            
            for (int i = 0; i < currentLevelSize; i++) { // iterate through level
                TreeNode *currentNode = myQueue.front(); // our current node working with
                myQueue.pop();
                
                
                // if currentNode has children, then we push into the queue
                // this is so we can populate the next level
                if (currentNode -> left != nullptr) {
                    myQueue.push(currentNode -> left);
                }
                
                if (currentNode -> right != nullptr) {
                    myQueue.push(currentNode -> right);
                }
                
                // push our current node's value into the vector so we can 
                // say we've traversed it
                currentLevel.push_back(currentNode -> val);
                
            }
            
            result.push_back(currentLevel); // push traversed level into our result vector
        }
        
        return result;
    }
};