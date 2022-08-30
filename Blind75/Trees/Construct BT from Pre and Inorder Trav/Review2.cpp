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
    // 08/30/2022 Construct BT from Pre and InOrder Traversal
    // Time Complexity: O(N), need to build N nodes 
    // Space Complexity: O(N), N recursive calls on stack worst case and N nodes of space created
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) { // if either array is empty, we don't have info
        // to build tree
            return nullptr;
        }
        
        int startingIndex = 0; // starting at index 0 of our preorder our highest level "root"
        
        return build(preorder, inorder, startingIndex, 0, inorder.size() - 1); // returns the tree
        // once it's done building 
    }
private:
    TreeNode *build (vector<int>& preorder, vector<int>& inorder, int &startingIndex, int leftBound, int rightBound) {
        if (leftBound > rightBound) { // if left > right, then we've build everything
            return nullptr;
        }
        
        // initalize a new node to add to our tree and build the tree with
        // we use the value of our current "root" in our preOrder array
        // first value of preorder array is the root of our array

        TreeNode *newNode = new TreeNode(preorder[startingIndex]);
        int split; // index of where the left and right nodes are for our specific node

        // traverse inorder array to find where the split for the left and right is 
        // once we find it break
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[startingIndex] == inorder[i]) {
                split = i;
                break;
            }
        }
        
        startingIndex++; // increment so we can work with the next node in the preorder array
        
        // recursively call to build children but change bounds depending on which child it is
        // if left, then we look at all values to the left of our split (currentNode) and if 
        // it's right, then look at all values to the right of our split
        newNode -> left = build(preorder, inorder, startingIndex, leftBound, split - 1);
        newNode -> right = build(preorder, inorder, startingIndex, split + 1, rightBound);
        
        return newNode; // return the node we just created
    }
};