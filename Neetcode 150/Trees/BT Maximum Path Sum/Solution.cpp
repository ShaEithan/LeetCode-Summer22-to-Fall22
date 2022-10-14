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
    // 10/13/2022 BT Maximum Path Sum (Hard) Trees
    // Time Complexity: O(N), worst case need to traverse N nodes
    // Space Complexity: O(logN) where logN is the height of the tree,
    // O(N) if BT is a LL
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    
    int dfs(TreeNode *root, int &maxSum) {
        if (root == nullptr) { // if node is null stop traversal
            return 0;
        }
        
        // find the maximum path on both left and right subtree
        // compare what's returned from dfs to 0, as we can have negative numbers in the tree
        int leftSum = max(dfs(root -> left, maxSum), 0);
        int rightSum = max(dfs(root -> right, maxSum), 0);
        
        // see if we have found a new maxPath
        // between current maxSum and currentSum (node + left tree max + right tree max)
        maxSum = max(maxSum, root -> val + leftSum + rightSum);
        
        
        // the value we return from this is the current Node plus the next node in the series that gives us 
        // the largest sum
        
        return root -> val + max(leftSum, rightSum);
    }
};