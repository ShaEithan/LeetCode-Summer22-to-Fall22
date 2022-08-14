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

// 5/25/22
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> node_queue;
        
        node_queue.push(root);
        int depth = 0;
        
        while (!node_queue.empty())
        {
            int current_level_size = node_queue.size();
            
            for (int i = 0 ;i < current_level_size;i++)
            {
                TreeNode *current_node = node_queue.front();
                node_queue.pop();
                
                if (current_node -> left != nullptr)
                {
                    node_queue.push(current_node -> left);
                }
                
                if (current_node -> right != nullptr)
                {
                    node_queue.push(current_node -> right);
                }
            }
            depth++;
        }
        
        return depth;
    }
};