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
    // 10/06/2022 Lowest Common Ancestor of a BST (Medium)
    
    // Time Complexity: O(N), need to traverse over N nodes worst case to find LCA
    // Space Complexity: O(logN), will have logN calls on rec stack at most due to height of a balanced BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == nullptr) { // if node is null, stop traversal
            return nullptr;
        }
        
        if (p -> val > root -> val && q -> val > root -> val) { // if p and q are greater than root, traverse to right sub tree
            return lowestCommonAncestor(root -> right, p , q);
        } else if (p -> val < root -> val && q -> val < root -> val) { // if p and q are less than root, traverse to left sub tree
            return lowestCommonAncestor(root -> left, p, q);
        } else { // if we've found our node between them, or if one of them is the current node then we return the current node
            return root;
        }
    }
};