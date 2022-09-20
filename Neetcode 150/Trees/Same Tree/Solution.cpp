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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == nullptr && q == nullptr) { // if both nodes are null, just return true
            return true;
        }
        
        if (p == nullptr || q == nullptr) { // if one node is not null and the other is, we don't have the same tree
            return false;
        }
        
        if (p -> val != q -> val) { // then compare the individual nodes values, because we've made sure that at this point, both nodes are not null
            return false;
        }
        
       return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};