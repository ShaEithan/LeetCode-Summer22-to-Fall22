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
    // DFS Approach 06/03/2022
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        // evaluates each node's left and right child and sees which node has the larger depth
        // and then saves it and increments
        
        int max_depth_of_left = maxDepth(root ->left);
        int max_depth_of_right = maxDepth(root -> right);
        
        return max(max_depth_of_left,max_depth_of_right) + 1; // for each recursive call, we increment so we
        // move to a new level, if the child is null, then it just returns 0
        
        // Time Complexity: O(logN + logN) as we need to traverse the left and right of each node
        // and if the left and right are the same depth, then we need to traverse 2logN times
        // as the max height of a Binary Tree is logN
        // Space Complexity: O(N), space needed for recursion stack
    }
    
    
};