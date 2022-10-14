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
    // 10/13/2022 Kth Smallest Element in a BST (Medium) DFS (Inorder), if Kth largest we do postOrder
    // Time Complexity: O(N), can need to traverse N nodes to find kth smallest element
    // Space Complexity: O(N), can have N calls at once if BST is a LL
    int kthSmallest(TreeNode* root, int k) {
        int result = 0; // pass as reference and we're going to return this with our kth smallest element
        dfs(root, k, result);
        return result;
    }
    void dfs(TreeNode * root, int &k, int &result) {
        if (root == nullptr) { // if null, stop traversal
            return;
        }
        
        // do in order traveral: left current right
        
        dfs(root -> left, k, result);
        
        k--; // deincrement k as we're one more element closer to our kth smallest value
        
        // access current and return it as the result if k = 0, we're on our kth element
        if (k == 0) {
            result = root -> val;
            return;
        }
        
        dfs(root -> right, k, result);
        
        return;
    }
};