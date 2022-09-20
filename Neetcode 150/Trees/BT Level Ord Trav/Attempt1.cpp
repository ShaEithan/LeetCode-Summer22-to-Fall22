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

// 05/22/2022

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        // Level order traversal (Traversal level by level of a BT) calls for 
        // Tree Breadth First Search (BFS) using a queue
        
        // result vector to return, containing vectors of ints
        vector<vector<int>> result;
        
        if (root == nullptr)
        {
            return result;
        }
        
        // queue of nodes to do BFS traversal
        queue<TreeNode*> my_queue;
        
        // push the root into the queue
        my_queue.push(root);
        
        while (!my_queue.empty())
        {
            // current level size should be the current size of the queue
            // tells how many times to iterate
            int current_size_level = my_queue.size();
            
            // vector to keep track of what level's we have traversed on the level
            vector<int> current_level_values;
            
            for (int i = 0; i < current_size_level ; i++)
            {
                TreeNode *current_node = my_queue.front();
                my_queue.pop();
                
                // push current value of visited node to vector of nodes
                // traversed for the level
                current_level_values.push_back(current_node -> val);
                
                // push children if they exist to the queue
                if (current_node -> left != nullptr)
                {
                    my_queue.push(current_node -> left);
                }
                if (current_node -> right != nullptr)
                {
                    my_queue.push(current_node -> right);
                }
            }
            // push current level traversal into the result vector
            result.push_back(current_level_values);
        }
        // Time: O(N)
        // Space: O(N)
        return result;
    }
};