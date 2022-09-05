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

// 09/05/2022 Invert Binary Tree (Easy)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == nullptr) { // if our current node is null, we just return the current node and stop traversal
            return root;
        }
        
        // must recursively call (DFS) on children first before we invert the current node's children 
        // otherwise we wouldn't actually be inverting anything.
        invertTree(root -> left);
        invertTree(root -> right);
        
        
        // invert/flip left and right in place using a temp node
        TreeNode *temp = root -> right;
        
        root -> right = root -> left;
        root -> left = temp;
        
        return root;
        
        // Time Complexity: O(N), invert and traverse N nodes
        // Space Complexity: O(logN), as the max calls on rec. stack is logN as the height of a BT.
    }
};