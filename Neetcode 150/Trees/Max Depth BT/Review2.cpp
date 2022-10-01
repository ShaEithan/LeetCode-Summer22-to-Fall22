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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        return max(findDepth(root -> left, 1), findDepth(root -> right, 1));
    }
    int findDepth(TreeNode* current, int depth) {
        if (current == nullptr) {
            return depth;
        }
        
        return max(findDepth(current -> left, depth + 1), findDepth(current -> right, depth + 1));
    }
};