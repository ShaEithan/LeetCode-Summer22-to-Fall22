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
    // 10/04/2022 Balanced Binary Tree (Easy)
    
    // Time Complexity: O(N), because we don't need to calculate height for every node. if we did
    // we would have a run time of O(n^2)
    
    // Space Complexity: O(logN), because the height of a BT when balanced is logN
    bool isBalanced(TreeNode* root) {
        int height = 0; 
        return dfs(root, height); // begin dfs traversal to find if the BT is balanced
    }
    
    bool dfs(TreeNode *root, int &height) {
        if (root == nullptr) {
            height = -1; // doesn't exist null
            return true; // null nodes are balanced
        }
        
        int leftSub = 0, rightSub = 0; // initalize variables for height of left and right subtree
        
        // if either of the subtrees of the current node are not balanced
        // then the tree is not balanced
        if (!dfs(root -> left, leftSub) || !dfs(root -> right, rightSub)) {
            return false;
        }
        
        // if the difference between left and right heights are greater than 1 then
        // the tree is not balanced
        if (abs(leftSub - rightSub) > 1) {
            return false;
        }
        
        // calculate the longest path comparing each subtree and add 1 as we've traversed one more time
        height = 1 + max(leftSub, rightSub);
        
        return true; // this sub tree is balanced! 
    }
    
};