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

// 08/02/2022 
class Solution {
public:
    
    // Time Complexity: O(N), build N nodes
    // Space Complexity: O(NlogN), N nodes of space and logN calls on recursion stack at one time
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int startingIndex = 0; // starting building from index 0 the BT root
        return build(preorder, inorder, startingIndex, 0, inorder.size() - 1); // returns head of the tree we are building
    }
    
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &startingIndex, int leftBound, int rightBound) {
        // stop traversal if our leftsplit index is greater than our rightsplit index
        if (leftBound > rightBound) {
            return nullptr;
        }
        
        // initialize our new node we're adding to our tree build
        TreeNode *currentNode = new TreeNode(preorder[startingIndex]);
        int split = 0; // identifying our split variable, what nodes are on the left of our current node and what nodes are on the right
        // of our current node in nthe inorder traversal
        
        for (int i = 0; i < inorder.size(); i++) { // finding the index of our currentNode we're building from in the inorder index
            if (preorder[startingIndex] == inorder[i]) {
                split = i; // this index is where our split
                break;
            }
        }
        
        startingIndex++; // moving to the next node to build
        
        // identifying and linking the nodes to the left and right of our current node
        // and are set oncne the functoin has returned the corresponding node
        currentNode -> left = build(preorder, inorder, startingIndex, leftBound, split - 1);
        currentNode -> right = build(preorder, inorder, startingIndex, split + 1, rightBound);
        
        return currentNode; // returnign the currentnode we've worked on
        
        
    }
};