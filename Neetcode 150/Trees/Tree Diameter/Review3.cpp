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
    // 10/05/2022 Diameter of BT (Easy)
    
    // Time Complexity: O(N), need to traverse through all nodes to find the longest path
    // between any two nodes in the tree
    // Space Complexity: O(logN), logN calls on stack due to height of BT 
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root, diameter); // do DFS on tree to find the diameter
        return diameter;
    }
    int findDiameter(TreeNode *root, int &diameter) {
        if (root == nullptr) { // if node is null then return 0
            return 0;
        }
         
        // we need to find the maximum diameter of the left and right subtrees
        int leftTree = findDiameter(root -> left, diameter);
        int rightTree = findDiameter(root -> right, diameter);
        
        // find the current maximum between current diameter and our current max
        diameter = max(diameter, leftTree + rightTree);
        
        // return 1 + the maximum between or left and right subtrees
        // as the diameter includes the node that the 2 nodes are related to
        return 1 + max(leftTree, rightTree);
        
    }
};