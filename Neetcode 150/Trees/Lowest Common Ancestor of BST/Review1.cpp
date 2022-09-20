#include <iostream>
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
    // 08/30/2022 Lowest Common Ancestor of a BST (Easy)
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // All values left of the root are less than the root and all values to the right are greater than
        // the root 
        
        if (p -> val > root -> val && q -> val > root -> val) { // if descendants are greater than our current node
            // we traverse to the right subtree
            return lowestCommonAncestor(root -> right, p, q);
        } else if (p -> val < root -> val && q -> val < root -> val){ // if descendants are less than our current node
            // we traverse to the left subtree
            return lowestCommonAncestor(root -> left, p, q);
        } else { // if neither applies we've found our LCA, or one of the nodes p or q equals the root of our BST
            // and the root is an ancestor of all nodes
            return root;
        }
    }
};