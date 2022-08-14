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
    int maxDepth(TreeNode* root) 
    {   
        if (root == nullptr)
        {
            return 0;
        }
    
        // Take a Breadth First Search Approach (BFS)
        // We're going to traverse level by level
        
        queue<TreeNode*> my_queue;
        
        // keeps track of our depth, will return this later
        int depth = 0;
        
        // start level by level traversal by pushing root
        my_queue.push(root);
        
        
        while (!my_queue.empty())
        {
            // when we get back to this line, the size of the queue
            // should be the number of nodes on the node about to be traversed
            
            int current_level_size = my_queue.size();
            
            for (int i = 0; i < current_level_size; i++)
            {
                TreeNode* current_node = my_queue.front();
                my_queue.pop();
                
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
            // increment depth because we traversed another level
            depth++;
        }
        
        return depth;
        
        // Time Complexity: O(N) traverse all N nodes level by level
        // Space Complexity: O(N) need to push N nodes into queue
    }
};