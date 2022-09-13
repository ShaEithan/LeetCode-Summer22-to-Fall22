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
    // 09/13/2022 Maximum Depth of BT (Easy)
    int maxDepth(TreeNode* root) {
        
        // Stop traversal if node is null, returns 0, so when we take the max between each child
        // then if one node is null and one is not we take the depth of the non null
        
        if (root == nullptr) {
            return 0;
        }
        
        // do DFS on each subtree of the root and then take the max depth between the 2
        int depthLeft = maxDepth(root -> left);
        int depthRight = maxDepth(root -> right);
        
        return max(depthLeft, depthRight) + 1;
    }
};