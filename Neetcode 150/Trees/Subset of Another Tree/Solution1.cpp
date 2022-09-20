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
    // Subtree of Another Tree (Easy) 572
    // Time Complexity: O(M+N), need to traverse over M + N nodes worst case (M and N being the # of nodes in both trees)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) { // if our 2nd tree is null, we return true because all leaves of our main tree, have a null sub tree
            return true;
        }
        
        if (root == nullptr) { // if we don't have a main tree, and the 2nd tree is non null, then obv the 2nd tree is not a sub tree of nothing!
            return false;
        }
        
        if (sameTree(root, subRoot)) { // but if we make it to this point, we call our helper function to find if our current root is the same as our 2nd tree
            return true; // if it is, return true
        } else { // if not, then we traverse our main tree and recursively call on each child to see if any of the current root's sub trees are the same as our 2nd tree
            return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
        }
    }
private:
    bool sameTree(TreeNode* root, TreeNode *subRoot) { // helper function to find if our current tree we're comparing our 2nd tree to is the same
        if (root == nullptr && subRoot == nullptr) { // if both current nodes are null, then we return true
            return true;
        }
        
        if (root == nullptr || subRoot == nullptr) { // if one is null and the other is not, return false, they're not the same
            return false;
        }
        
        // we compare values not nodes themselves because they have different addresses 
        if (root -> val == subRoot -> val) { // if the values of each current node are the same, then we continue to traverse to find if the trees are the same
            return sameTree(root -> left, subRoot -> left) && sameTree(root -> right, subRoot -> right);
        }
    
        return false; // if values don't match then we continue recursively traversing. 
    }
};