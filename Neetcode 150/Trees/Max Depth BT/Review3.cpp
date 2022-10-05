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
    // 10/05/2022 Max Depth of BT (Easy)
    // Time Complexity: O(N), need to traverse N nodes
    // Space Complexity: O(logN), logN calls on stack at most due to height of balanced BT
    int maxDepth(TreeNode* root) {
        if (root == nullptr) { // if the node is null, then return 0, there is no depth
            return 0;
        }
        
        // do dfs on left and right subtrees and they should return the
        // maximum depth of each subtree from the root
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        
        // for every traversal add 1 to whichever child has the greater depth
        return 1 + max(left, right);
    }
};