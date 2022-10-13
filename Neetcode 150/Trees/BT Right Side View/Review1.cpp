#include <vector>
#include <queue>

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
    // 10/11/2022 BT Right Side View BFS
    // Time Complexity: O(N)
    // Space Complexity: O(N), if BT is a LL, otherwise O(logN) height of tree
    
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) { // if no tree exists
            return {};
        }
        
        vector<int> result;
        queue<TreeNode*> nQueue; // queue for BFS trav
        
        nQueue.push(root); // begin trav
        
        while(!nQueue.empty()) {
            int levelSize = nQueue.size();
            
            // iterate through the level
            for (int i = 0; i < levelSize; i++) {
                TreeNode *current = nQueue.front();
                nQueue.pop();
                if (i == 0) { // first node is our "right side view"
                    result.push_back(current -> val);
                }
                
                // add next nodes to the next level
                if (current -> right != nullptr) { // want right side, so we push right node before left node in queue
                    nQueue.push(current -> right);
                }
                
                if (current -> left != nullptr) {
                    nQueue.push(current -> left);
                }
            }
        }
        
        return result;
    }
};