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
    // 09/20/2022 Lowest Common Ancestor of BST (Medium) O(N) (worst case need to traverse N nodes), O(logN) as the maximum number of calls
    // is the height of the BST 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // In a BST all values to the left of the root are less than the root and all values to the
        // right are greater
        
        // The way we solve this problem is to use that to our advantage! 
        
        // we traverse depending on the value of our currentNode. Is our currentnode less than both nodes? go to left subtree
        // is it greater than both nodes?  go to right subtree
        // or is one of the nodes the current node or are we between both nodes p and q? 
        // so we just return our current node! This saves us the edge case if the current node was the root, then the common ancestor is the current Node!
        
        // use DFS traversal
        
        if (root == nullptr) {
            return root;
        }
        
        if (p -> val > root -> val && q -> val > root -> val) { // if both nodes are greater than our current node, traverse to right subtree for larger values
            return lowestCommonAncestor(root -> right, p, q);
        } else if (p -> val < root -> val && q -> val < root -> val) { // if both nodes are less than our current node, traverse to left subtree for smaller values
            return lowestCommonAncestor(root -> left, p, q); 
        } else { // if we're beteen both nodes, then we've found our common lowest ancestor, or one of the nodes is the root, return the current node 
            return root;
        }
    }
};

