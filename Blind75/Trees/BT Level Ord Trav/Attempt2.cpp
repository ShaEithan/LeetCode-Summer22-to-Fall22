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

// 05/25/22
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        
        vector<vector<int>> result;
        
        if (root == nullptr)
        {
            return result;
        }
        
        queue<TreeNode*> my_queue;
        
        my_queue.push(root);
        
        while (!my_queue.empty())
        {
            int current_level_size = my_queue.size();
            
            vector<int> current_level;
            
            for (int i = 0; i < current_level_size; i++)
            {
                TreeNode *current_node = my_queue.front();
                my_queue.pop();
                
                current_level.push_back(current_node -> val);
                
                if (current_node -> left != nullptr)
                {
                    my_queue.push(current_node -> left);
                }
                if (current_node -> right != nullptr)
                {
                    my_queue.push(current_node -> right);
                }
            }
            
            result.push_back(current_level);
        }
        return result;
    }
};