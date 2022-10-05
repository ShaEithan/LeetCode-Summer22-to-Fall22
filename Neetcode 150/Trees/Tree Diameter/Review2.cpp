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
    // 10/04/2022 Diameter of Binary Tree (Easy)
    // Time Complexity: O(N), need to traverse N nodes
    // Space Complexity: O(logN), due to height of BT being logN, we'd have at most
    // logN calls on recursion stack at once
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter); // begin dfs traversal from root
        return diameter;
    }
    // dfs will return us the diameter of the tree
    int dfs(TreeNode *root, int &diameter) {
        if (root == nullptr) { // if we can't traverse anymore return 0;
            return 0;
        }
        
        // traverse the left and right subtrees
        int left = dfs(root -> left, diameter);
        int right = dfs(root -> right, diameter);
        
        // take the max of the current max diameter and the current height of both left and right subtrees
        diameter = max(diameter, left + right);
        
        // for every traversal, add 1 to the largest height of the current subtree
        return 1 + max(left, right);
    }
};