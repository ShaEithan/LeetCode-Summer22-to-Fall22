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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int startingIndex = 0; // pass in a starting index to begin building our Tree
        return build(preorder, inorder, startingIndex, 0, inorder.size() - 1); 
    }
    
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &index, int leftBound, int rightBound) {
        
        // if leftSplit index becomes greater than rightSplit, then 
        // we don't need to keep building
        if (leftBound > rightBound) {
            return nullptr;
        }
        
        // initialize our current "root" that we're building off of
        // every node in preorder in that order is the order of our next "root"
        // to work off of
        
        TreeNode *currentRoot = new TreeNode(preorder[index]);
        
        int splitIndex = 0; // variable to keep track of where we split our tree from left subtree
        // and right subtree
        
        // Iterate through our inorder traversal array, to find where our "split" node is
        // all nodes before it are in the left subtree of our mid node
        // all nodes after it belong in the right sub tree of our current "split" node 
        for (int i = 0; i < inorder.size(); i++) {
            // if we find our current "root" index at index i of postord
            // then it's location is where we can differentiate the left and right subtrees
            // of our current node
            if (preorder[index] == inorder[i]) {
                splitIndex = i;
                break;
            }
        }
        
        index++; // we found our split for this current node, so we move on to find the next split
        // by incrementing our index to keep track of our current "root" nodes
        
        // recursively call build for the children of our currentRoot node
        // so we can build it child by child
        
        // splitIndex + 1 for our left bound and keep the right bound, as we need 
        // all valuess to the right of our split for the right child of our currentRoot
        
        // splitIndex - 1, for our right bound and keep left bound, as we need all valuess
        // to the left our split to build the left child of our currentroot
        currentRoot -> left = build(preorder, inorder, index, leftBound, splitIndex - 1);
        currentRoot -> right = build(preorder, inorder, index, splitIndex + 1, rightBound);
        
        return currentRoot;
    }
    
    // Time Complexity: O(N), need to build N nodes
    // Space Complexity: O(N), we'd have N calls on the recursion stack at most if 
    // BT was a LL, O(logN), avg case
};