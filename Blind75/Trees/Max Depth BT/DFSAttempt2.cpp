using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

// 07/26/2022
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // base case: if the current node we're accessing is null we stop traversal
        if (root == nullptr) {
            return 0;
        }
        // Our DFS traversal, find the max between the depth of the left child and right child
        // of the current node
        return max(1 + maxDepth(root -> left), 1 + maxDepth(root -> right));
        
        // Time Complexity: O(N), need to traverse all nodes 
        // Space Complexity: O(logN), if the tree is balanced because the amount of recusrive calls
        // on the stack depends on the height of the BT
    }
};