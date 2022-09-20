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
    // 98. Validate Binary Search Tree (Medium)
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL){
            return true;
        } 
        // current node, long min (-inf), long max (inf)
        return check(root, LONG_MIN, LONG_MAX);
    }
    bool check(TreeNode* root, long minimum, long maximum){
        
        if(root == NULL) { // if we've gotten to the point the root is null, we know it's valid so return true
            return true;
        }
        
        // see if it's within bounds. root must be between min and max values
        if(root->val <= minimum || root->val >= maximum) {
            return false;
        }
        
        // do DFS and recurisvely check left and right sub trees with different bounds
        // left sub tree keeps minimum bound, but the new upper bound is the current root's value
        // right sub tree keeps the maximum bound, but the new lower bound is the current root's value
        return check(root->left, minimum, root->val) && check(root->right, root->val, maximum);
    }
};