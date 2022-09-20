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
    int diameter;
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        calculateHeight(root);
        return diameter;
    }
private:
    int calculateHeight(TreeNode *root) {
        // base case to stop recursion and DFS traversal
        if (root == nullptr) {
            return 0;
        } 
        
        
        // calculate the height of our left tree and right tree of the current node
        // (otherwise knownn as the logest path)
        int leftTreeHeight = calculateHeight(root -> left);
        int rightTreeHeight = calculateHeight(root -> right);
        
        // update the diameter if the leftPath + rightPath is larger than our current diameter
        
        int currentDiameter = leftTreeHeight + rightTreeHeight;
            
        // reassigning treeDiameter if the currentDiameter is larger
        diameter = max(currentDiameter, diameter);
        
        // calculate the height of the current node, so we can use it to calculate the diameter
        return max(leftTreeHeight, rightTreeHeight) + 1; 
    }
    // Time Complexity: O(N), need to traverse every node
    // Space Complexity: O(logN), avg case depending on the height of the BT or O(N), if 
    // tree is a LL.
};