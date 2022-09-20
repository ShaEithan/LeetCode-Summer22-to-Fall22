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
// 08/30/2022 Max Depth of BT (Easy)

// Time Complexity: O(N), traverse N nodes
// Space Complexity: O(logN), in a balanced BT, we will have logN calls on the recursion stack at once
// as it's the height of the tree

    int maxDepth(TreeNode* root) {
        if (root == nullptr) { // if node is null, just stop traversal there
            return 0;
        }
        
        int depthOfLeft = maxDepth(root -> left); // find maxDepth of the left subtree
        int depthOfRight = maxDepth(root -> right); // find maxDepth of the right subtree
        
        return max(depthOfLeft, depthOfRight) + 1; // take the max between both and add 1 as 
        // the root itself is considered a level
    }
};