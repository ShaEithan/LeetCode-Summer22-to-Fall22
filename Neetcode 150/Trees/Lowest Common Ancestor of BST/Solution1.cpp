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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == nullptr) {
            return root;
        }
        
        TreeNode *current = root;
        
        while (current != nullptr) {
            if (p -> val > current -> val && q -> val > current -> val) {
                current = current -> right;
            } else if (p -> val < current -> val && q -> val < current -> val) {
                current = current -> left;
            } else {
                return current;
            }
        }
        
        return current;
    }
};