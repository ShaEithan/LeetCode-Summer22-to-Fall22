#include <iostream>

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
    // 10/12/2022 Validate BST
    // Time Complexity: O(N), have to visit each node to check if it's a valid BST
    // Space Complexity: O(logN), logN is height of the tree
    // can be O(N) if each node has only one child
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) { // if empty tree = true
            return true;
        }
        
        // set bounds for helper function
        long minimum = LONG_MIN;
        long maximum = LONG_MAX;
        
        return check(root, minimum, maximum); // return if true or false
    }
    
    bool check(TreeNode *root, long minimum, long maximum) {
        if (root == nullptr) { // if we make it to a null node, then that path is true
            return true;
        }
        
        // make sure we're in bounds
        // current node must be between min and max or equal to either
        
        if (root -> val >= maximum || root -> val <= minimum) {
            return false;
        }
        
        // traverse subtrees and set up new bounds
        // if going left, min stays the same and currentnode becomes new max
        // if going right, max stays the same and currentNode becomes new min
        
        return check(root -> left, minimum, root -> val) && check(root -> right, root -> val, maximum);
    }
};