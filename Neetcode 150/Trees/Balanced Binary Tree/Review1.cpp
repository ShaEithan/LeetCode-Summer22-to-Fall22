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
    // 10/05/2022 Balanced Binary Tree (Easy)
    
    // Time Complexity: O(N), only need to traverse each node once. We use height as a parameter
    // so we don't have to call a helper function that has to traverse N nodes each time which would then
    // make the complexity O(n^2)
    
    // Space Complexity: O(logN), logN calls on stack at most due to height of Balanced BT 
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }
    bool dfs(TreeNode* root, int &height) {
        // edge case: if the current node is null, it doesn't exist
        // so it has a height of -1
        // null nodes are also balanced
        if (root == nullptr) {
            height = -1;
            return true;
        }
        
        // We have to first see if the children of this node are all balanced
        
        int leftHeight = 0, rightHeight = 0;
        
        // if either subtree is not balanced, then tree is not balanced
        if (!dfs(root -> left, leftHeight) || !dfs(root -> right, rightHeight)) {
            return false;
        }
        
        // now we compare heights of each subtree, if the absolute value of the differece is greater than 1
        // then the tree isn't balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        
        // as we traverse, we add 1 to whichever height is greater between children
        height = 1 + max(leftHeight, rightHeight);
        
        // we've passed all our checks so true W
        return true;
    }
};